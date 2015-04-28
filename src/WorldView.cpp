#include <vector>
#include <tuple>
#include <allegro5/allegro.h>
#include <iostream>
#include <ctime>
#include <sstream>

#include "WorldView.hpp"
#include "Displayable.hpp"
#include "View.hpp"
#include "BiomeView.hpp"
#include "BiomeTile.hpp"
#include "World.hpp"
#include "TextPane.hpp"
#include "ResourceSet.hpp"
#include "Font.hpp"


bool WorldView::init()
{
	uint8_t result = false;
	if( model && fontset && tileset)
	{
		auto worldTileSet = model->getWorldTileSet();

		World& world = model->getWorld();
		
		TileSet& ts = tileset->get(std::get<0>(worldTileSet));
		ts.init(std::get<1>(worldTileSet), 
			    std::get<2>(worldTileSet));

		uint16_t worldMapWidth = world.worldMap.size();
		uint16_t worldMapHeight = world.worldMap[0].size();

		biomeDisplay.init(0,
			      		  0,
			      		  768,
			      		  768,
			      		  worldMapWidth,
			      		  worldMapHeight,
			      		  &ts);

	//	std::vector<Tile>* tile_array = biomeDisplay.getTiles();

		redrawWorld();		

		/* @todo Create the TextPane to give info about the Biome */
		Font & f = fontset->get("Roboto-Bold.ttf");
		biomeInfo.init(f.get(12),768,0, 256, 112); /* each line is 16 pixels tall so 16*7=112 */
		biomeInfo.setFore(model->getThemeFont());
		biomeInfo.setBack(model->getThemeBackground());
		updateBiomePane();

		commandInfo.init(f.get(12),768, 672,256,80); /* 672 means leave a line of empty space at the bottom */
		commandInfo.setFore(model->getThemeFont());
		commandInfo.setBack(model->getThemeBackground());
		commandInfo.write("                              Commands");
		commandInfo.write(" ");
		commandInfo.write("  Enter -> Enter the Biome View");
		commandInfo.write("  Escape -> Return to the Title View");
		commandInfo.write("  Arrow Keys -> Move");
		commandInfo.render();

		drawList.push_back(&biomeInfo);
		drawList.push_back(&commandInfo);
		drawList.push_back(&biomeDisplay);
		result = is_init = true;

	}
	return result;
}

void WorldView::redrawWorld()
{
	World& world = model->getWorld();
	if (world.getFirstTime())
	{
		std::vector<Tile>* tile_array = biomeDisplay.getTiles();
		uint16_t worldMapWidth = world.worldMap.size();
		//uint16_t worldMapHeight = world.worldMap[0].size();

		for (uint16_t i = 0; i< (*tile_array).size(); i++)
		{
			(*tile_array)[i] = world.getTile(i%worldMapWidth, i/worldMapWidth);
		}

		// put the player on the world map
		Player& player = model->getPlayer();
		Tile & t = (*tile_array)[player.getWorldX()+player.getWorldY()*worldMapWidth];
		
		/*base colors for now */
		t.setIndex(player.getChar());
		t.setFore(model->getThemeBackground());
		t.setBack(model->getThemeFont());

		biomeDisplay.setDirty();
		biomeDisplay.render();
	}
}

DefinedViews WorldView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::WORLD_VIEW;
	std::vector<Tile>* tile_array = biomeDisplay.getTiles();
	World& world = model->getWorld();
	uint16_t worldMapWidth = world.worldMap.size();
	uint16_t worldMapHeight = world.worldMap[0].size();

	Player& player = model->getPlayer();
	uint16_t playerWorldX = player.getWorldX();
	uint16_t playerWorldY = player.getWorldY();
	uint16_t newX = playerWorldX;
	uint16_t newY = playerWorldY;
	bool move = false;
	bool switchView = false;
	

	switch(ev->keyboard.keycode)
	{
            
        case ALLEGRO_KEY_ENTER:
            dv = DefinedViews::BIOME_VIEW;
            redrawPlayer = true;
            switchView = true;
            break;
		case ALLEGRO_KEY_ESCAPE: /* return to tile Game*/
			dv = DefinedViews::TITLE_VIEW;
			break;
		case ALLEGRO_KEY_LEFT:
			if( playerWorldX - 1 >= 0 )
			{
				newX -= 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_RIGHT:
			if( playerWorldX + 1 < worldMapWidth )
			{
				newX += 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_UP:
			if( playerWorldY - 1 >= 0 )
			{
				newY -=1 ;
				move = true;
			}
			break;
		case ALLEGRO_KEY_DOWN:
			if( playerWorldY + 1 < worldMapHeight )
			{
				newY += 1;
				move = true;
			}
			break;
		default:
			break; 
	}

	if( move || switchView)
	{
		/* Also need to update the TextPane based on the Biome */
		/* Reset the map tile to terrain instead of the player */
		Tile t_orig = world.getTile(playerWorldX,playerWorldY);
		Tile& t_map = (*tile_array)[playerWorldX+playerWorldY*worldMapWidth];
		t_map.setIndex(t_orig.getIndex());	
		t_map.setFore(t_orig.getFore());
		t_map.setBack(t_orig.getBack());
		if(move)
		{
			/* draw the player */
			Tile& t_player = (*tile_array)[newX+newY*worldMapWidth];
			t_player.setIndex(player.getChar());
			t_player.setFore(model->getThemeBackground());
			t_player.setBack(model->getThemeFont());
			/* update the players position */
			player.setWorldPosition(newX,newY);

		}
		updateBiomePane();
		/* redraw the display */
		biomeDisplay.setDirty();
		biomeDisplay.render();
	}
	return dv;
}

DefinedViews WorldView::handleEvent(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::WORLD_VIEW;

	if( ev )
	{
		switch (ev->type)
		{
			case ALLEGRO_EVENT_KEY_CHAR:
				dv = handleKeyPress(ev);
				break;
			default:
				break;
		}
	}
	return dv;

}

void WorldView::updateBiomePane()
{
	/* note the pane is currently calibrated for exactly 7 lines if we want to 
	   change this, we need to also change the size of the pane */
	std::ostringstream oss;

	World& world = model->getWorld();
	Player& player = model->getPlayer();
	uint16_t playerWorldX = player.getWorldX();
	uint16_t playerWorldY = player.getWorldY();

	biomeInfo.write("                              Biome Info");
	biomeInfo.write(" ");

	BiomeTile& bt = world.worldMap[playerWorldX][playerWorldY].getBiomeData();
	oss <<"  Biome Type: "<<bt.getBiomeTypeName();
	biomeInfo.write(oss.str());
	oss.str("");
	oss<<"  Elevation: "<<bt.getElevation();
	biomeInfo.write(oss.str());
	oss.str("");
	oss<<"  Rainfall: "<<bt.getRainfall();
	biomeInfo.write(oss.str());
	oss.str("");
	oss<<"  Temperature: "<<bt.getTemperature();
	biomeInfo.write(oss.str());
	oss.str("");
	if (bt.getDrainage())
	{
		biomeInfo.write("  River");
	}
	else if(bt.getLake())
	{
		biomeInfo.write("  Lake");
	}
	else
	{
		biomeInfo.write(" ");
	}
	biomeInfo.render();
}

std::vector<Displayable*>& WorldView::draw()
{
	redrawWorld();
	if(redrawPlayer)
	{
		std::vector<Tile>* tile_array = biomeDisplay.getTiles();
		Player& player = model->getPlayer();
		uint16_t playerX = player.getWorldX();
		uint16_t playerY = player.getWorldY();
		uint16_t worldMapWidth = model->getWorld().getXSize();
		Tile& t = (*tile_array)[playerX+playerY*worldMapWidth];
		/* draw the player */
		t.setIndex(player.getChar());
		t.setFore(model->getThemeBackground());
		t.setBack(model->getThemeFont());
		/* redraw the display */
		biomeDisplay.setDirty();
		biomeDisplay.render();

		updateBiomePane();

		redrawPlayer = false;
	}
	return drawList;
}

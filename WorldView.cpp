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
	int result = false;
	if( model && fontset && tileset)
	{
		auto worldTileSet = model->getWorldTileSet();

		World& world = model->getWorld();
		world.buildBiomes(); /* generate terrain */
                
                

		TileSet& ts = tileset->get(std::get<0>(worldTileSet));
		ts.init(std::get<1>(worldTileSet), 
			    std::get<2>(worldTileSet));

		int worldMapWidth = world.worldMap.size();
		int worldMapHeight = world.worldMap[0].size();

		biomeDisplay.init(0,
			      		  0,
			      		  768,
			      		  768,
			      		  worldMapWidth,
			      		  worldMapHeight,
			      		  &ts);

		std::vector<Tile>* tile_array = biomeDisplay.getTiles();

		for (int i = 0; i< (*tile_array).size(); i++)
		{
			(*tile_array)[i] = world.getTile(i%worldMapWidth, i/worldMapWidth);
		}

		// put the player on the world map
		Player& player = model->getPlayer();
		(*tile_array)[player.getWorldX()+player.getWorldY()*worldMapWidth].setIndex(player.getChar());

		/*base colors for now */
		(*tile_array)[player.getWorldX()+player.getWorldY()*worldMapWidth].setFore(model->getThemeBackground());
		(*tile_array)[player.getWorldX()+player.getWorldY()*worldMapWidth].setBack(model->getThemeFont());
		biomeDisplay.render();

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

DefinedViews WorldView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::WORLD_VIEW;
	std::vector<Tile>* tile_array = biomeDisplay.getTiles();
	World& world = model->getWorld();
	int worldMapWidth = world.worldMap.size();
	int worldMapHeight = world.worldMap[0].size();

	Player& player = model->getPlayer();
	int playerWorldX = player.getWorldX();
	int playerWorldY = player.getWorldY();
	int newX = playerWorldX;
	int newY = playerWorldY;
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
		Tile t = world.getTile(playerWorldX,playerWorldY);
		(*tile_array)[playerWorldX+playerWorldY*worldMapWidth].setIndex(t.getIndex());	
		(*tile_array)[playerWorldX+playerWorldY*worldMapWidth].setFore(t.getFore());
		(*tile_array)[playerWorldX+playerWorldY*worldMapWidth].setBack(t.getBack());
		if(move)
		{
			/* draw the player */
			(*tile_array)[newX+newY*worldMapWidth].setIndex(player.getChar());
			(*tile_array)[newX+newY*worldMapWidth].setFore(model->getThemeBackground());
			(*tile_array)[newX+newY*worldMapWidth].setBack(model->getThemeFont());
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
	int playerWorldX = player.getWorldX();
	int playerWorldY = player.getWorldY();

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
	if(redrawPlayer)
	{
		std::vector<Tile>* tile_array = biomeDisplay.getTiles();
		Player& player = model->getPlayer();
		int playerX = player.getWorldX();
		int playerY = player.getWorldY();
		int worldMapWidth = model->getWorld().getXSize();
		/* draw the player */
		(*tile_array)[playerX+playerY*worldMapWidth].setIndex(player.getChar());
		(*tile_array)[playerX+playerY*worldMapWidth].setFore(model->getThemeBackground());
		(*tile_array)[playerX+playerY*worldMapWidth].setBack(model->getThemeFont());
		/* redraw the display */
		biomeDisplay.setDirty();
		biomeDisplay.render();

		updateBiomePane();

		redrawPlayer = false;
	}
	return drawList;
}
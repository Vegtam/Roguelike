#include <vector>
#include <tuple>
#include <allegro5/allegro.h>
#include <iostream>

#include "WorldView.hpp"
#include "Displayable.hpp"
#include "View.hpp"
#include "World.hpp"
#include "DiamondSquare.hpp"


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

		int worldMapWidth = world.baseMap.size();
		int worldMapHeight = world.baseMap[0].size();

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

		/* put the player on the map */
		Player& player = model->getPlayer();
		(*tile_array)[player.GetX()+player.GetY()*worldMapWidth].setIndex(player.GetChar());

		/*base colors for now */
		(*tile_array)[player.GetX()+player.GetY()*worldMapWidth].setFore(model->getThemeBackground());
		(*tile_array)[player.GetX()+player.GetY()*worldMapWidth].setBack(model->getThemeFont());
		biomeDisplay.render();

		/* @todo Create the TextPane to give info about the Biome */

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
	int worldMapWidth = world.baseMap.size();
	int worldMapHeight = world.baseMap[0].size();

	Player& player = model->getPlayer();
	int playerX = player.GetX();
	int playerY = player.GetY();
	int newX = playerX;
	int newY = playerY;
	bool move = false;
	
	switch(ev->keyboard.keycode)
	{
		case ALLEGRO_KEY_ESCAPE: /* return to tile Game*/
			dv = DefinedViews::TITLE_VIEW; 
			break;
		case ALLEGRO_KEY_LEFT:
			if( playerX - 1 >= 0 )
			{
				newX -= 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_RIGHT:
			if( playerX + 1 < worldMapWidth )
			{
				newX += 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_UP:
			if( playerY - 1 >= 0 )
			{
				newY -=1 ;
				move = true;
			}
			break;
		case ALLEGRO_KEY_DOWN:
			if( playerY + 1 < worldMapHeight )
			{
				newY += 1;
				move = true;
			}
			break;
		default:
			break; 
	}
	if( move )
	{
		/* Also need to update the TextPane based on the Biome */
		/* Reset the map tile to terrain instead of the player */
		(*tile_array)[playerX+playerY*worldMapWidth].setIndex( world.getTile(playerX,playerY).getIndex());	
		(*tile_array)[playerX+playerY*worldMapWidth].setFore(world.getTile(playerX,playerY).getFore());
		(*tile_array)[playerX+playerY*worldMapWidth].setBack(world.getTile(playerX,playerY).getBack());
		/* draw the player */
		(*tile_array)[newX+newY*worldMapWidth].setIndex(player.GetChar());
		(*tile_array)[newX+newY*worldMapWidth].setFore(model->getThemeBackground());
		(*tile_array)[newX+newY*worldMapWidth].setBack(model->getThemeFont());
		/* update the players position */
		player.SetPosition(newX,newY);
		
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

std::vector<Displayable*>& WorldView::draw()
{
	return drawList;
}
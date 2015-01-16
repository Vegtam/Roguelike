#include "BiomeView.hpp"
#include <iostream>


bool BiomeView::init()
{
    int result = false;
    if( model and fontset and tileset)
    {
        
        
        
        Biome& biome = model->getWorld().worldMap[model->getPlayer().getWorldX()][model->getPlayer().getWorldY()];
        
        auto biomeTileSet = model->getBiomeTileSet();
        
        TileSet& ts = tileset->get(std::get<0>(biomeTileSet));
                    
        ts.init(std::get<1>(biomeTileSet), std::get<2>(biomeTileSet));

        int biomeMapWidth = biome.regionMap.size();
        int biomeMapHeight = biome.regionMap[0].size();
        
        localeDisplay.init(0, 0, 768, 768, biomeMapWidth, biomeMapHeight, &ts);
        drawList.push_back(&localeDisplay);
        /* @todo Create the TextPane to give info about the Biome */

        //drawList.push_back(&localeDisplay);
        result = is_init = true;

    }
    return result;
}


DefinedViews BiomeView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::BIOME_VIEW;
	
	Biome& biome = model->getWorld().worldMap[model->getPlayer().getWorldX()][model->getPlayer().getWorldY()];
	int regionMapWidth = biome.regionMap.size();
	int regionMapHeight = biome.regionMap[0].size();

	Player& player = model->getPlayer();        
        
	int playerX = player.getRegionX();
	int playerY = player.getRegionY();
	int newX = playerX;
	int newY = playerY;
        
        redraw(playerX, playerY);
        
	bool move = false;
	
        
        

	switch(ev->keyboard.keycode)
	{
            //Vegtam added code here for debugging Regions, feel free to delete.
                //case ALLEGRO_KEY_ENTER:
                //    dv = DefinedViews::BIOME_VIEW;
                 //   break;
            //end of Vegtam's code.
		case ALLEGRO_KEY_ESCAPE: /* return to tile Game*/
			dv = DefinedViews::TITLE_VIEW; 
			break;
                case ALLEGRO_KEY_W: /* return to world Map*/
                        
                        dv = DefinedViews::WORLD_VIEW;
                        break;
		case ALLEGRO_KEY_LEFT:
			if( playerX - 1 >= 0 )
			{
				newX -= 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_RIGHT:
			if( playerX + 1 < regionMapWidth )
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
			if( playerY + 1 < regionMapHeight )
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
            /* update the players position */
            redraw(playerX, playerY);
            player.setRegionPosition(newX,newY);
	}
	return dv;
}

void BiomeView::redraw(int xPos, int yPos)
{
    /* Also need to update the TextPane based on the Biome */
		/* Reset the map tile to terrain instead of the player */
    
    std::vector<Tile>* tile_array = localeDisplay.getTiles();
    
    Biome& biome = model->getWorld().worldMap[model->getPlayer().getWorldX()][model->getPlayer().getWorldY()];
    int regionMapWidth = biome.regionMap.size();
    int regionMapHeight = biome.regionMap[0].size();

      

    int playerX = xPos;
    int playerY = yPos;
    int newX = playerX;
    int newY = playerY;
    
    Tile t = biome.getTile(playerX,playerY);
    (*tile_array)[playerX+playerY*regionMapWidth].setIndex(t.getIndex());	
    (*tile_array)[playerX+playerY*regionMapWidth].setFore(t.getFore());
    (*tile_array)[playerX+playerY*regionMapWidth].setBack(t.getBack());
    /* draw the player */
    (*tile_array)[newX+newY*regionMapWidth].setIndex(model->getPlayer().getChar());
    (*tile_array)[newX+newY*regionMapWidth].setFore(model->getThemeBackground());
    (*tile_array)[newX+newY*regionMapWidth].setBack(model->getThemeFont());
    

    /* redraw the display */
    localeDisplay.setDirty();
    localeDisplay.render();
}

DefinedViews BiomeView::handleEvent(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::BIOME_VIEW;

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

std::vector<Displayable*>& BiomeView::draw()
{
    if(!drawn)
    {
        Biome& biome = model->getWorld().worldMap[model->getPlayer().getWorldX()][model->getPlayer().getWorldY()];
        
        int biomeMapWidth = biome.regionMap.size();
        int biomeMapHeight = biome.regionMap[0].size();
     
        std::vector<Tile>* tile_array = localeDisplay.getTiles();
        
        for (int i = 0; i< (*tile_array).size(); i++)
	{
            (*tile_array)[i] = biome.getTile(i%biomeMapHeight, i/biomeMapWidth);
	}

        // put the player on the map
        Player& player = model->getPlayer();
        (*tile_array)[player.getRegionX()+player.getRegionY()*biomeMapWidth].setIndex(player.getChar());

        //base colors for now
        (*tile_array)[player.getRegionX()+player.getRegionY()*biomeMapWidth].setFore(model->getThemeBackground());
        (*tile_array)[player.getRegionX()+player.getRegionY()*biomeMapWidth].setBack(model->getThemeFont());
        redraw(player.getRegionX(), player.getRegionY());
        localeDisplay.render();
        bool drawn = true;
    }
	return drawList;
}

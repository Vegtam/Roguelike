#include <allegro5/allegro.h>
#include <iostream>
#include <vector>
#include <assert.h>

#include "Displayable.hpp"
#include "BiomeView.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "TileSet.hpp"
#include "Tile.hpp"
#include "View.hpp"
#include "Biome.hpp"

/*
Coordinate relationships

player.worldX,player.worldY -> 17x17 biome on view switch, center depends on proximity to edge of world
                            -> indicates 9 biomes 
player.regionX,player.regionY -> on transition from world to region = worldX*17+9,worldY*17+9
                              -> Increments as we move around the world, bounds are 0-worldWidth*17,0-worldHeight*17

Will track the bounding box of the screen in regionCorrdinates
Bounding box is 33x33 tiles which show the tiles from the 9 biomes (but some are only partial)

we need to track the window center seperate from the player
*/


bool BiomeView::init()
{
    int result = false;
    if( model and fontset and tileset)
    {
        auto biomeTileSet = model->getBiomeTileSet();
        
        TileSet& ts = tileset->get(std::get<0>(biomeTileSet));
                    
        ts.init(std::get<1>(biomeTileSet), std::get<2>(biomeTileSet));

        /* localeDisplay is indepentent of the player so we use the model 
           defined tileset and the fixed 33x33 dimensions*/
        localeDisplay.init(0, 0, 768, 768, kMapWidth, kMapHeight, &ts);
        /* @todo Create the TextPane to give info about the Biome */

        std::vector<Tile>* tile_array = localeDisplay.getTiles();
        Tile defaultTile(0);

        for (uint32_t i = 0; i< (*tile_array).size(); i++)
        {
            (*tile_array)[i] = defaultTile;
        }

        Font & f = fontset->get("Roboto-Bold.ttf");

        commandInfo.init(f.get(12),768, 640,256,112); /* 640 means leave a line of empty space at the bottom */
        commandInfo.setFore(model->getThemeFont());
        commandInfo.setBack(model->getThemeBackground());
        commandInfo.write("                              Commands");
        commandInfo.write(" ");
        commandInfo.write("  W -> Return to the World View");
        commandInfo.write("  U -> Scroll without moving the Player");
        commandInfo.write("  C -> Re-center on the Player");
        commandInfo.write("  Escape -> Return to the Title View");
        commandInfo.write("  Arrow Keys -> Move");
        commandInfo.render();

        drawList.push_back(&commandInfo);

        drawList.push_back(&localeDisplay);
        result = is_init = true;

    }
    return result;
}


DefinedViews BiomeView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::BIOME_VIEW;
	
	World& world = model->getWorld();
	int regionMapWidth = world.getXSize()*Biome::kMapWidth;
	int regionMapHeight = world.getYSize()*Biome::kMapHeight;

	Player& player = model->getPlayer();        
        
	int playerX = bound? player.getRegionX():pseudoX;
	int playerY = bound? player.getRegionY():pseudoY;
	int newX = 0;
	int newY = 0;
        
	bool move = false;

    //std::cout<<"regionMapWidth "<<regionMapWidth<<std::endl;
    //std::cout<<"regionMapHeight "<<regionMapHeight<<std::endl;
	
	switch(ev->keyboard.keycode)
	{
            //Vegtam added code here for debugging Regions, feel free to delete.
                //case ALLEGRO_KEY_ENTER:
                //    dv = DefinedViews::BIOME_VIEW;
                 //   break;
            //end of Vegtam's code.
		case ALLEGRO_KEY_ESCAPE: /* return to tile Game*/
			dv = DefinedViews::TITLE_VIEW;
            drawn = false;
			break;
        case ALLEGRO_KEY_W: /* return to world Map*/
                
            dv = DefinedViews::WORLD_VIEW;
            drawn = false;
            break;
        case ALLEGRO_KEY_U:
            //Unbind the view from the character
            bound = false;
            pseudoX = player.getRegionX();
            pseudoY = player.getRegionY();
            //no move here
            break;
        case ALLEGRO_KEY_C:
            //recenter on the character
            bound = true;
            rebound = true;
            playerX = player.getRegionX();
            playerY = player.getRegionY();
            move = true; //forces recenter
            break;
		case ALLEGRO_KEY_LEFT:
			if( playerX - 1 >= 0 )
			{
				newX = -1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_RIGHT:
			if( playerX + 1 < regionMapWidth )
			{
				newX = 1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_UP:
			if( playerY - 1 >= 0 )
			{
				newY = -1;
				move = true;
			}
			break;
		case ALLEGRO_KEY_DOWN:
			if( playerY + 1 < regionMapHeight )
			{
				newY = 1;
				move = true;
			}
			break;
		default:
			break; 
	}
        
	if( move )
	{
        if(bound)
        {
            playerX +=newX;
            playerY +=newY;
            /* update the players position */
            player.setRegionPosition(playerX,playerY);
            player.setWorldPosition(playerX/Biome::kMapWidth, 
                                    playerY/Biome::kMapHeight);
        }
        else
        {
            pseudoX+=newX;
            pseudoY+=newY;
        }
        redraw(newX, newY);
	}
	return dv;
}

/* instead of taking the absolute position of the character in the world of regions xPos and yPos should be the
   offset from the current positions (so each ranges from [-1,1] )*/
void BiomeView::redraw(int xPos, int yPos)
{
    /* Also need to update the TextPane based on the Biome */
		/* Reset the map tile to terrain instead of the player */
    
    Player & player = model->getPlayer(); 
    World & world = model->getWorld();
    int32_t pWorldX = bound?player.getWorldX():pseudoX/Biome::kMapWidth;
    int32_t pWorldY = bound?player.getWorldY():pseudoY/Biome::kMapHeight;
    //int i, j;


    int32_t pRegionX = bound?player.getRegionX():pseudoX;
    int32_t pRegionY = bound?player.getRegionY():pseudoY;

    /*
    viewWindow changes
    1. When the player uses the world map to move to a different region
    2. When the player gets within 3 tiles of the edge of the viewWindow and the window is not against the world of regions edge
    3. When the set of current regions changes
    */

    if ((pRegionX/Biome::kMapWidth != pWorldX || 
        pRegionY/Biome::kMapHeight != pWorldY) || rebound)
    {
        if (!rebound)
        {
            /* if the region coordinates aren't in the correct region per the world coordinates then
               place the player in the center of the region specified by the world coordinates */
            pRegionX = pWorldX*Biome::kMapWidth+ Biome::kMapWidth/2;
            pRegionY = pWorldY*Biome::kMapHeight+ Biome::kMapHeight/2;

            if (bound)
            {
                player.setRegionPosition(pRegionX,pRegionY);
            }
        }
        else
        {
            rebound = false;
        }

        /* Now move the view window upper left corner to ensure the player is in it, centered if possible */
        if( pRegionX-16 >= 0)
        {
            if( pRegionX+16 < world.getXSize()*Biome::kMapWidth)
            {
                viewWindowX = pRegionX-16;
            }
            else
            {
                /* 33 back from the edge of the world of regions map */
                viewWindowX = world.getXSize()*Biome::kMapWidth-BiomeView::kMapWidth;
            }
        }
        else
        {
            viewWindowX = 0;
        }
        if( pRegionY-16 >= 0)
        {
            if( pRegionY+16 < world.getYSize()*Biome::kMapWidth)
            {
                viewWindowY = pRegionY-16;
            }
            else
            {
                /* 33 back from the edge of the world of regions map */
                viewWindowY = world.getYSize()*Biome::kMapHeight-BiomeView::kMapHeight;
            }
        }
        else
        {
            viewWindowY = 0;
        }
    } 
    else if ((((pRegionX-viewWindowX) <= 3  && xPos == -1)||
             ((pRegionY-viewWindowY) <= 3 && yPos == -1) ||
             ((viewWindowX+kMapWidth - pRegionX) <= 3 && xPos==1) ||
             ((viewWindowY+kMapHeight - pRegionY) <= 3 && yPos ==1)) || not bound)
    {
        /* if the player has moved within 3 tiles of the edge of the current view window start sliding the view window 
            but don't move the view window past the edge
        */
        if(viewWindowX + xPos > 0 )
        {
            if(viewWindowX + xPos + BiomeView::kMapWidth < world.getXSize()*Biome::kMapWidth)
            {
                viewWindowX +=xPos;
            }
            else
            {
                viewWindowX = world.getXSize()*Biome::kMapWidth-BiomeView::kMapWidth;
            }
        }
        else
        {
            viewWindowX = 0;
        }
        if(viewWindowY + yPos > 0 )
        {
            if(viewWindowY + yPos + BiomeView::kMapHeight < world.getYSize()*Biome::kMapHeight)
            {
                viewWindowY +=yPos;
            }
            else
            {
                viewWindowY = world.getYSize()*Biome::kMapHeight-BiomeView::kMapHeight;
            }
        }
        else
        {
            viewWindowY = 0;
        }
    }

    /* now that we have the view window and the player coordinates its time to set up the tiles */

    /* we have screwed up the math above if pRegionX and pRegionY are not greater than or equal to viewWindowX and viewWindowY respectively */
    
    //std::cout << "Relative Coords:" <<std::endl;
    //std::cout << viewWindowX << " " << viewWindowY << std::endl;
    //std::cout << player.getRegionX() << " " << player.getRegionY() << std::endl;

    assert( pRegionX >= viewWindowX && pRegionY >= viewWindowY);
    
    std::vector<Tile>* tile_array = localeDisplay.getTiles();

    
    /* set the map tiles */
    for (uint32_t i = 0; i < BiomeView::kMapWidth; i++)
    {
        for (uint32_t j = 0; j <BiomeView::kMapHeight; j++)
        {
            Biome & biome = world.worldMap[(viewWindowX+i)/Biome::kMapWidth][(viewWindowY+j)/Biome::kMapHeight];
            Region & region = biome.regionMap[(viewWindowX+i)%Biome::kMapWidth][(viewWindowY+j)%Biome::kMapHeight];
            (*tile_array)[i+j*BiomeView::kMapWidth] = region.getRegionData().getTile();

        }
    }

    /* We are done with the pseudo character at this point, lets see if the player should be on the screen */
    pRegionX = player.getRegionX();
    pRegionY = player.getRegionY();

    if(pRegionX >= viewWindowX && 
       pRegionX < viewWindowX+BiomeView::kMapWidth &&
       pRegionY >= viewWindowY && 
       pRegionY < viewWindowY+BiomeView::kMapHeight)
    {
        /*set the player */
        Tile& t = (*tile_array)[pRegionX-viewWindowX + (pRegionY-viewWindowY)*BiomeView::kMapWidth];
        t.setIndex(model->getPlayer().getChar());
        t.setFore(model->getThemeBackground());
        t.setBack(model->getThemeFont());
    }

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
        redraw(0, 0);
        drawn = true;
    }
	return drawList;
}

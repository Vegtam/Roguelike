#include "RegionTile.hpp"
#include <iostream>

void RegionTile::displayRegionTileType(int regionType)
{
    switch(regionType)
    {
        case 0: //Ocean
            displayID = 247; // ~ 
                
            // blue          
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            
            break;
            
        case 1: //Land
            displayID = 177; // tiny checkerboard
                
            // medium brown
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            break;
            
        case 2: // Mediterranean forests

            displayID = 23; //coneiduous tree

            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // light green
            foregroundR = 1;
            foregroundG = 200;
            foregroundB = 1;

            break;

        case 3: // Desert

            displayID = 15; // sun

            // tan
            backgroundR = 250;
            backgroundG = 225;
            backgroundB = 160;

            // orange
            foregroundR = 255;
            foregroundG = 185;
            foregroundB = 1;

            break;
            
        default: //Ocean
            displayID = 247; // ~ 
                
            // blue          
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            
            break;
    }
}

Tile RegionTile::getTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}

void RegionTile::setRegionTileType()
{
    int r = rand() % 4;
    displayRegionTileType(1);
}
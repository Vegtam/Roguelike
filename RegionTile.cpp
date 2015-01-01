#include "RegionTile.hpp"


void RegionTile::setRegionTileType(int regionType)
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
    }
}

Tile RegionTile::displayRegionTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}
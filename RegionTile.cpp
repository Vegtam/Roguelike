#include "RegionTile.hpp"
#include "World.hpp"
#include "Model.hpp"
#include <iostream>

void RegionTile::displayRegionTileType(int regionType)
{
    switch(regionType)
    {
            case 0: // ocean 
                
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
        
            case 1: // Tropical moist forests 
                
                displayID = 5; // deciduous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 2: //Tropical dry forests
                
                displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 3: // Tropical coniferous forests
                
                displayID = 6; // coniferous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
            case 4: // Temperate broadleaf and mixed forests
                
                displayID = 23; // coneiduous tree (yes I made that up)
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 5: // Temperate coniferous forests
                
                displayID = 6; // coniferous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 6: //  Boreal forests/taiga 
                
                displayID = 6; // coniferous tree 
                
                // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                break;
                
            case 7: // Tropical grasslands, savannas, and shrublands
                
                displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
            case 8: // Temperate grasslands, savannas, and shrublands
                
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
                
            case 9: // Flooded grasslands and savannas
                
                displayID = 176; // thin diagonal lines
                
                // brownish grey 
                backgroundR = 130;
                backgroundG = 100;
                backgroundB = 75;
                
                // medium blue
                foregroundR = 125;
                foregroundG = 135;
                foregroundB = 75;
                
                break;
                
            case 10: // Montane grasslands and shrublands
                
                displayID = 94; // pointed arch 
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // dark gray 
                foregroundR = 135;
                foregroundG = 130;
                foregroundB = 120;
                
                break;
                
            case 11: // Tundra (Arctic)
                
                displayID = 177; // tiny checkerboard, prev 236 filled small circle
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
            case 12: // Mediterranean forests
                
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
                
            case 13: // Desert
                
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
                
            case 14: // Mangrove
                
                displayID = 244; // big tree
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
            default: // Not Set!!!! For debugging purposes
                
                displayID = 33; // !
                
                // Red
                backgroundR = 250;
                backgroundG = 1;
                backgroundB = 1;
                
                // Orange
                foregroundR = 250;
                foregroundG = 125;
                foregroundB = 1;
                
                break;
    }
}

Tile RegionTile::getTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}

void RegionTile::setRegionTileType(int biomeType)
{
    
    
    displayRegionTileType(biomeType);
}
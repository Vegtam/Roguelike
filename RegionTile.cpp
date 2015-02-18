#include "RegionTile.hpp"
#include "World.hpp"
#include "Model.hpp"
#include <iostream>

void RegionTile::displayRegionTileType(int regionType)
{
    switch(regionType)
    {
            case 0: // ocean 
                buildOceanRegion();
                //displayID = 247; // ~ 
                
                // blue          
                //backgroundR = 1;
                //backgroundG = 100;
                //backgroundB = 255;
                
                // light blue
                //foregroundR = 175;
                //foregroundG = 230;
                //foregroundB = 245;
                
                break;
        
            case 1: // Tropical moist forests 
                
                       
                buildTropicalMoistForestRegion();
                
                break;
                
            case 2: //Tropical dry forests
                
                buildTropicalDryForestRegion();
                
                break;
                
            case 3: // Tropical coniferous forests
                
                buildTropicalConiferousForestRegion();
                
                break;
                
            case 4: // Temperate broadleaf and mixed forests
                
                buildTemperateBroadleafMixForestRegion();
                
                break;
                
            case 5: // Temperate coniferous forests
                
                buildTemperateConiferousForestRegion();
                
                break;
                
            case 6: //  Boreal forests/taiga 
                
                buildBorealForestRegion();
                
                break;
                
            case 7: // Tropical grasslands, savannas, and shrublands
                
                buildTropicalGrasslandRegion();
                
                break;
                
            case 8: // Temperate grasslands, savannas, and shrublands
                
                buildTemperateGrasslandRegion();
                
                break;
                
            case 9: // Flooded grasslands and savannas
                
                buildFloodedGrasslandRegion();
                
                break;
                
            case 10: // Montane grasslands and shrublands
                
                buildMontaneRegion();
                
                break;
                
            case 11: // Tundra (Arctic)
                
                buildTundraRegion();
                
                break;
                
            case 12: // Mediterranean forests
                
                buildMediterraneanRegion();
                
                break;
                
            case 13: // Desert
                
                buildDesertRegion();
                
                break;
                
            case 14: // Mangrove
                
                buildMangroveRegion();
                
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

void RegionTile::buildOceanRegion() 
{
    int regionNum = rand() % 4;
    
    switch(regionNum)
    {
        case 0:
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
            
        case 1:
            displayID = 247; // ~ 
                
            // green-blue          
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 200;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
                
        case 2:
            displayID = 247; // ~ 
                
            // greenish blue          
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            break;
            
        case 3:
            displayID = 247; // ~ 
                
            // dark blue          
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            break;
            
        case 4:
            displayID = 247; // ~ 
                
            // blue-green          
            backgroundR = 1;
            backgroundG = 200;
            backgroundB = 255;

            // light blue
            foregroundR = 175;
            foregroundG = 230;
            foregroundB = 245;
            
    }
}

void RegionTile::buildTropicalMoistForestRegion()
{
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            displayID = 5; // deciduous tree
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 1:
            displayID = 5; // deciduous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 2:
            displayID = 177; // tiny checkerboard
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
                
            break;
                
        case 3:
            displayID = 177; // deciduous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 4:
            displayID = 177; // deciduous tree
                
            // dark green
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
                
        case 5:
            displayID = 177; // deciduous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium brown
                foregroundR = 150;
                foregroundG = 100;
                foregroundB = 1;
                
                forest = true;
                
                break;
            
    }
}

void RegionTile::buildTropicalDryForestRegion() 
{
    
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 2:
            displayID = 177; // tiny checkerboard
            
            // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
            // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 3:
            displayID = 44; //comma
            
            // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
            // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                break;
                
        case 4:
            displayID = 5; // deciduous tree
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                     
    }
            
}

void RegionTile::buildTropicalConiferousForestRegion()
{
            
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        case 0:
            displayID = 6; // coneiferous tree
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 1:
            displayID = 6; // coneiferous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 2:
            displayID = 177; // tiny checkerboard
                
            // dark green
            backgroundR = 1;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
                
            break;
                
        case 3:
            displayID = 6; // coneiferous tree
                
            // medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;

            // dark green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 4:
            displayID = 6; // coneiferous tree
                
            // dark green
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
                
        case 5:
            displayID = 6; // coneiferous tree
                
                // dark green
                backgroundR = 1;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium brown
                foregroundR = 150;
                foregroundG = 100;
                foregroundB = 1;
                
                forest = true;
                
                break;
            
    }
}

void RegionTile::buildTemperateBroadleafMixForestRegion()
{
    
    int regionNum = rand() % 6;
    
    switch(regionNum)
    {
        case 0: 
                displayID = 6; // coneiforous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 1:
                
            displayID = 6; // coneiferous tree (yes I made that up)
                
                // medium? brown
                backgroundR = 175;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 2:
            
            displayID = 6; // coneiferous tree (yes I made that up)
                
                // medium? brown
                backgroundR = 150;
                backgroundG = 125;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 3:
            
            displayID = 5; // deciduous tree
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 4:
            
            displayID = 5; // deciduous tree
                
                // medium brown
                backgroundR = 175;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
        case 5:
            displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green 
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                forest = true;
                
                break;
                
    }
}

void RegionTile::buildTemperateConiferousForestRegion()
{
    int regionNum = rand() % 5;
    
    switch(regionNum)
            
    {
        case 0:
            
            displayID = 6; // coniferous tree

            // medium brown
            backgroundR = 150;
            backgroundG = 100;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 1:
            
            displayID = 6; // coniferous tree
            
            //medium green
            backgroundR = 1;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium brown
            foregroundR = 100;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 2:
            
            displayID = 177; //tiny checkerboard
            
            //medium brown
            backgroundR = 100;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
        case 3:
            
            displayID = 5; //deciduous tree
            
            //medium brown
            backgroundR = 100;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 4:
            
            displayID = 6; //coniferous tree
            
            //dark brown
            backgroundR = 150;
            backgroundG = 150;
            backgroundB = 1;
            
            //medium green
            foregroundR = 1;
            foregroundG = 100;
            foregroundB = 1;
            
            forest = true;
            
            break;
    }
}

void RegionTile::buildBorealForestRegion()
{
                
    int regionNum = rand() % 5;
    
    switch(regionNum)
    {
        
        case 0:
                
            displayID = 6; // coniferous tree 

            // light green
            backgroundR = 1;
            backgroundG = 200;
            backgroundB = 1;

            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;

            break;
                
        case 1:
            
            displayID = 6; //coniferous tree
            
            // white
            backgroundR = 255;
            backgroundG = 245;
            backgroundB = 245;
                
            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
            
        case 2:
            
            displayID = 177; // tiny checkerboard
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
        case 3:
            
            displayID = 177; // tiny checkerboard
                                
                // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                break;
                
        case 4:
            
            displayID = 6; //coniferous tree
            
            // light green
                backgroundR = 1;
                backgroundG = 200;
                backgroundB = 1;
                
            // medium green
            foregroundR = 1;
            foregroundG = 150;
            foregroundB = 1;
            
            forest = true;
            
            break;
    }
                
}

void RegionTile::buildTropicalGrasslandRegion()
{
    displayID = 177; // tiny checkerboard 
                
                // dark brown
                backgroundR = 125;
                backgroundG = 75;
                backgroundB = 1;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                //break;
}

void RegionTile::buildTemperateGrasslandRegion()
{
    
                
                displayID = 177; // tiny checkerboard
                
                // medium brown
                backgroundR = 150;
                backgroundG = 100;
                backgroundB = 1;
                
                // medium green
                foregroundR = 1;
                foregroundG = 150;
                foregroundB = 1;
                
                //break;
}

void RegionTile::buildFloodedGrasslandRegion()
{
    displayID = 176; // thin diagonal lines
                
                // brownish grey 
                backgroundR = 130;
                backgroundG = 100;
                backgroundB = 75;
                
                // medium blue
                foregroundR = 125;
                foregroundG = 135;
                foregroundB = 75;
                
                //break;
}

void RegionTile::buildMontaneRegion() 
{
    displayID = 94; // pointed arch 
                
                // light green
                backgroundR = 115;
                backgroundG = 185;
                backgroundB = 1;
                
                // dark gray 
                foregroundR = 135;
                foregroundG = 130;
                foregroundB = 120;
                
                //break;
}

void RegionTile::buildTundraRegion()
{
    
                        
                
                displayID = 177; // tiny checkerboard, prev 236 filled small circle
                
                // white
                backgroundR = 255;
                backgroundG = 245;
                backgroundB = 245;
                
                // gray
                foregroundR = 175;
                foregroundG = 175;
                foregroundB = 150;
                
                //break;
               
}


void RegionTile::buildMediterraneanRegion() 
{
    displayID = 23; //coneiduous tree
                
                // medium green
                backgroundR = 1;
                backgroundG = 150;
                backgroundB = 1;
                
                // light green
                foregroundR = 1;
                foregroundG = 200;
                foregroundB = 1;
                
                //break;
}

void RegionTile::buildDesertRegion()
{
    
                displayID = 15; // sun
                
                // tan
                backgroundR = 250;
                backgroundG = 225;
                backgroundB = 160;
                
                // orange
                foregroundR = 255;
                foregroundG = 185;
                foregroundB = 1;
                
                //break;
}

void RegionTile::buildMangroveRegion()
{
        displayID = 244; // big tree
                
                // medium blue
                backgroundR = 1;
                backgroundG = 125;
                backgroundB = 255;
                
                // dark green
                foregroundR = 1;
                foregroundG = 100;
                foregroundB = 1;
                
                //break;
}

Tile RegionTile::getTile()
{
    return Tile(displayID, al_map_rgb(backgroundR,backgroundG,backgroundB), al_map_rgb(foregroundR,foregroundG,foregroundB));
}

void RegionTile::setRegionTileType(int biomeType)
{
    
    
    displayRegionTileType(biomeType);
}
#include "Biome.hpp"
#include "Region.hpp"
#include <vector>
#include <iostream>


Biome::Biome() : regionMap(17, std::vector<Region>(17)){fillRegions();}

bool Biome::fillRegions()
{
    //build empty region map
    for(int x = 0; x < regionMap.size(); ++x)
    {
        for(int y = 0; y < regionMap[0].size(); ++y)
        {
            
            regionMap[x][y].getRegionData().setRegionTileType();
            
        }
    }
    
    return true;
        
}

Tile Biome::getTile(int xPos, int yPos)
{
    Tile tileDisplay = regionMap[xPos][yPos].getRegionData().getTile();
    
    return tileDisplay;
    
}
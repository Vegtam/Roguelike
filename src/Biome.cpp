#include "Biome.hpp"
#include "BiomeTile.hpp"
#include "Region.hpp"
#include <vector>
#include <iostream>




bool Biome::fillRegions(int biomeType)
{
    
    for(int x = 0; x < regionMap.size(); ++x)
    {
        for(int y = 0; y < regionMap[0].size(); ++y)
        {
            regionMap[x][y].getRegionData().setRegionTileType(biomeType);
            float elevation = getBiomeData().getElevation();
        }
    }
    
    return true;
        
}

Tile Biome::getTile(int xPos, int yPos)
{
    Tile tileDisplay = regionMap[xPos][yPos].getRegionData().getTile();
    
    return tileDisplay;
    
}
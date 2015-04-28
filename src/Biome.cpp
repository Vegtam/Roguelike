#include "Biome.hpp"
#include "BiomeTile.hpp"
#include "Region.hpp"
#include <vector>
#include <iostream>




bool Biome::fillRegions(uint32_t biomeType)
{
    
    for(uint32_t x = 0; x < regionMap.size(); ++x)
    {
        for(uint32_t y = 0; y < regionMap[0].size(); ++y)
        {
            regionMap[x][y].getRegionData().setRegionTileType(biomeType);
            //float elevation = getBiomeData().getElevation();
        }
    }
    
    return true;
        
}

Tile Biome::getTile(uint32_t xPos, uint32_t yPos)
{
    Tile tileDisplay = regionMap[xPos][yPos].getRegionData().getTile();
    
    return tileDisplay;
    
}

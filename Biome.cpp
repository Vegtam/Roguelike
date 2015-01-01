#include "Biome.hpp"
#include "Region.hpp"

void Biome::fillRegions()
{
    for(int x = 0; x < regionMap.size(); ++x)
    {
        for(int y = 0; x < regionMap[0].size(); ++y)
        {
            regionMap[x][y].getRegionData().setRegionTileType(1);
        }
    }
        
}

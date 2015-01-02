#include "Biome.hpp"
#include "Region.hpp"
#include <vector>

void Biome::fillRegions()
{
    
    
    for(int x = 0; x < 17; ++x)
    {
        for(int y = 0; x < 17; ++y)
        {
            regionMap[x][y].getRegionData().setRegionTileType(1);
        }
    }
        
}

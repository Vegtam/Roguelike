#ifndef BIOME_HPP_
#define BIOME_HPP_

#include <stdint.h>
#include <vector>
#include "BiomeTile.hpp"
#include "Region.hpp"

class Biome
{
private:
    
    BiomeTile tile;
    

public:
	constexpr static uint32_t kMapWidth = 17;
	constexpr static uint32_t kMapHeight = 17;
	std::vector<std::vector<Region> > regionMap;
    
    Biome() : regionMap(kMapWidth, std::vector<Region>(kMapHeight)){};
    virtual ~Biome(){};
    inline BiomeTile& getBiomeData(){return tile;};

    
    Tile getTile(int xPos, int yPos);
    
    /* add functions to do stuff with regionMap here */
    bool fillRegions(int biomeType);
    
};

#endif
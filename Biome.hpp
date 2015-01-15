#ifndef BIOME_HPP_
#define BIOME_HPP_

#include <stdio.h>
#include <vector>
#include "BiomeTile.hpp"
#include "Region.hpp"

class Biome
{
private:
    
    BiomeTile tile;
	

public:
    Biome() : regionMap(17, std::vector<Region>(17)){};
    virtual ~Biome(){};
    std::vector<std::vector<Region> > regionMap;
    inline BiomeTile& getBiomeData(){return tile;};

    
    Tile getTile(int xPos, int yPos);

    /* add functions to do stuff with regionMap here */
    bool fillRegions(int biomeType);
    
};

#endif
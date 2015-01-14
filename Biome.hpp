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
	Biome();
	virtual ~Biome(){};
        std::vector<std::vector<Region> > regionMap;
	inline BiomeTile& getBiomeData(){return tile;};
        
        bool fillRegions();
        Tile getTile(int xPos, int yPos);
	
	/* add functions to do stuff with regionMap here */
};

#endif
#ifndef BIOME_HPP_
#define BIOME_HPP_

#include <vector>
#include "BiomeTile.hpp"
#include "Region.hpp"

class Biome
{
private:
	BiomeTile tile;
	std::vector<std::vector<Region>> regionMap;
public:
	Biome(){};
	virtual ~Biome(){};
	inline BiomeTile& getBiomeData(){return tile;};
	
	/* add functions to do stuff with regionMap here */
};

#endif
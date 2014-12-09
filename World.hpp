#ifndef WORLD_HPP
#define	WORLD_HPP
#include <vector>
#include <array>
#include "Biome.hpp"
#include "Tile.hpp"
#include "TerrainGenerator.hpp"

class World {
public:
    World(int xSize, int ySize);
    virtual ~World();
    std::vector <std::vector<Biome> > baseMap;
    Tile getTile(int xPos, int yPos);
    void buildBiomes();
private:
    bool isElevationSpike();
    int getElevation();

};

#endif	/* WORLD_HPP */


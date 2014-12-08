#include "World.hpp"
#include "Biome.hpp"
#include "Tile.hpp"
#include <vector>
#include <iostream>

World::World(int xSize, int ySize) : baseMap(xSize, std::vector<Biome>(ySize)) {
}

World::~World() {
}


Tile World::getTile(int xPos, int yPos)
{
    int displayId = baseMap[xPos][yPos].getDisplayID();
    
    return Tile(displayId, al_map_rgb(120,130,140), al_map_rgb(40,30,20));
    
}

void World::buildBiomes()
{
    TerrainGenerator tGen;
    
    for(int x = 0; x < baseMap.size(); x++)
    {
        for(int y = 0; y < baseMap[x].size(); y++)
        {
            baseMap[x][y].setDisplayID(tGen.generateRandomTerrain());
        }
            
    }
}


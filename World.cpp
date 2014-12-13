#include "World.hpp"
#include "Biome.hpp"
#include "Tile.hpp"
#include "DiamondSquare.hpp"
#include <vector>
#include <iostream>

World::World(int xSize, int ySize) : baseMap(xSize, std::vector<Biome>(ySize)) {
}

World::~World() {
}


Tile World::getTile(int xPos, int yPos)
{
    Tile tileDisplay = baseMap[xPos][yPos].getTile();
    
    return tileDisplay;
    
}

void World::buildBiomes()
{
    
    DiamondSquare elevationMap;
    
    elevationMap.generateMap();
    elevationMap.printMap(0);
    
    
    for(int x = 0; x < baseMap.size(); x++)
    {
        for(int y = 0; y < baseMap[x].size(); y++)
        {
            
            baseMap[x][y].setBiomeAttributes(0);
        }
            
    }
     
}


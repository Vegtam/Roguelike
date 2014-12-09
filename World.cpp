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
    Tile tileDisplay = baseMap[xPos][yPos].getTile();
    
    return tileDisplay;
    
}

bool World::isElevationSpike()
{
    int randomNumber = rand() % 4;
    if(randomNumber == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int World::getElevation()
{
    bool spike = isElevationSpike();
    
    int elevation;
    
    if(spike)
    {
        int spikeLevel = rand() % 4;
        
        switch(spikeLevel)
        {
            case 0:
                elevation = rand() % 1000 + 500;
                break;
            case 1:
                elevation = rand() % 2500 + 1001;
                break;
            case 2:
                elevation = rand() % 5000 + 2501;
                break;
            case 3:
                elevation = rand() % 10000 + 5001;
                break;
        }
    }
    else
    {
        elevation = rand() % 500;
    }
    
    return elevation;
       
}

void World::buildBiomes()
{
    
    TerrainGenerator tGen;
    
    for(int x = 0; x < baseMap.size(); x++)
    {
        for(int y = 0; y < baseMap[x].size(); y++)
        {
            int elevation = getElevation();
            
            std::cout << elevation << std::endl;
            baseMap[x][y].setBiomeAttributes(tGen.generateRandomTerrain());
        }
            
    }
}


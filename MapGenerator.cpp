#include "MapGenerator.hpp"
#include "TerrainGenerator.hpp"
#include <iostream>
#include <vector>

MapGenerator::MapGenerator() {
}

MapGenerator::MapGenerator(const MapGenerator& orig) {
}

MapGenerator::~MapGenerator() {
}




std::vector< std::vector<int> > MapGenerator::randomTerrainMap(int xSize, int ySize)
{
    TerrainGenerator tGen;
    int xPos;
    int yPos;

    std::vector<std::vector<int> > workingMap(xSize, std::vector<int>(ySize, 0));
    
    for(yPos = 0; yPos < ySize; yPos++)
    {
        for(xPos = 0; xPos < xSize; xPos++)
        {
            workingMap[xPos][yPos] = tGen.generateRandomTerrain();
        }
    }
    return workingMap;
}
#include <cstdlib>
#include <ctime>
#include "TerrainGenerator.hpp"
using namespace std;

TerrainGenerator::TerrainGenerator() {
}

TerrainGenerator::TerrainGenerator(const TerrainGenerator& orig) {
}

TerrainGenerator::~TerrainGenerator() {
}

int TerrainGenerator::generateRandomTerrain()
{
    
    terrain = rand() % 15;
    return terrain;
}

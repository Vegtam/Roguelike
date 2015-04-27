#ifndef TERRAINGENERATOR_HPP
#define	TERRAINGENERATOR_HPP
#include <cstdlib>
#include <ctime>

class TerrainGenerator {
public:
    TerrainGenerator();
    TerrainGenerator(const TerrainGenerator& orig);
    virtual ~TerrainGenerator();
    int terrain;
    int generateRandomTerrain();
private:

};

#endif	/* TERRAINGENERATOR_HPP */



#ifndef MAPGENERATOR_HPP
#define	MAPGENERATOR_HPP
#include <vector>

class MapGenerator {
public:
    MapGenerator();
    MapGenerator(const MapGenerator& orig);
    virtual ~MapGenerator();
    
    std::vector< std::vector<int> > randomTerrainMap(int xSize, int ySize);
    
    
private:

};

#endif	/* MAPGENERATOR_HPP */


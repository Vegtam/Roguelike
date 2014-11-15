#include "Map.hpp"

/*class Map : public

{
private:
    int type;
    array features;
    int xSize;
    int ySize;
    int zSize;

public:
    Map();
    ~Map();

    int setType(); //Set the map type - Overland, Town, Dungeon, Cave, Castle, others? Determines features and creatures
    int populateFeatures; //Randomly place trees, rocks, water, hills, valleys, mountains, oceans, walls, treasure, etc...
    int setXSize(); //Set width of map.. can it be circular? X360->X0<-X360
    int setYSize(); //Set map height..
    int setZSize();  // maybe generate layers with z level to simulate hills, valleys, mountains, etc...
*/

Map::Map()
{

}

Map::~Map()
{

}

int getType()
{
    mapType = 0;
    return mapType;
}

int populateFeatures(int mapType)
{
    // randomly generate objects from object::mapFeature class, depending on mapType?

    return mapFeatures;
}

void setXSize(int mapType)

{

}

void setYSize(int mapType)

{

}

void setZSize(int mapType)

{

}


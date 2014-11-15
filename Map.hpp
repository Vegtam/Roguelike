#ifndef MAP_HPP
#define MAP_HPP
//I have no idea how to implement a navigable map, it probably involves an update function in main?
//a heartbeat function to update the map, or it might be better to update upon action, even if we
//include a wait one step?
class Map
{
private:
    int mapType;
    int mapFeatures[10]; //start with 10, work up?
    int xSize;
    int ySize;
    int zSize;

public:
    Map();
    ~Map();
    void Init();
    int getType();  //Get the map type - Overland, Town, Dungeon, Cave, Castle, others? Determines features and creatures
                    //Determined by passage type?  Door, cavern entrance...
    int populateFeatures(int mapType);   //Randomly place trees, rocks, water, hills, valleys, mountains, oceans, walls, treasure, etc...
                            //Should this be done by the objects?
    int setXSize(); //Set width of map.. can it be circular? X360->X0<-X360
    int setYSize(); //Set map height..
    int setZSize();  // maybe generate layers with z level to simulate hills, valleys, mountains, etc...

};

#endif // MAP_HPP

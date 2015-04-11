

#ifndef WORLD_HPP
#define	WORLD_HPP
#include <vector>
#include <array>
#include <string>
#include <math.h>
#include "Biome.hpp"
#include "BiomeTile.hpp"
#include "Tile.hpp"
#include "TerrainGenerator.hpp"

class World {
    
private:
    const int xSize;
    const int ySize;
    int prevX;
    int prevY;
    float min, max;
    int worldsCount = 0;
    bool firstTime;
    
public:
    
    World(int width, int height);
    virtual ~World();
    inline int getXSize() {return xSize;};
    inline int getYSize() {return ySize;};
    inline bool getFirstTime(){bool t = firstTime; firstTime= false; return t;} 
    std::vector <std::vector<Biome> > worldMap;
    Tile getTile(int xPos, int yPos);

    void buildBiomes();
protected:    
    void generateBaseTemperature(std::vector<std::vector<int> >& temperatureMap);
    void fillMap(std::vector<std::vector<float> >& fillerMap);   
    void generateRiverSource(std::vector<std::vector<float> >& elevationMap, 
                                std::vector<std::vector<float> >& rainfallMap,
                                std::vector<std::vector<bool> > drainageMap );
    void generateRiverPath(int x, int y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    void generateErosion(int x, int y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    void fillRiver(int x, int y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    //float random(float max);
    void printMap(int mapType, std::vector<std::vector<float> >& fillerMap);
    bool checkMaps(std::vector<std::vector<float> >& elevationMap, 
                   std::vector<std::vector<float> >& rainfallMap);
   
    struct color{
	//v[0]=red, v[1]=green, v[2]=blue
	unsigned char v[3];
	
	inline color(unsigned char r, unsigned char g, unsigned char b){
		v[0]=r;
		v[1]=g;
		v[2]=b;
	}
    };
    
    color lerp(color c1, color c2, float value);

};

#endif	/* WORLD_HPP */


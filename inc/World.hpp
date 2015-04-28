

#ifndef WORLD_HPP
#define	WORLD_HPP
#include <vector>
#include <array>
#include <string>
#include <math.h>
#include "Biome.hpp"
#include "BiomeTile.hpp"
#include "Tile.hpp"
//#include "TerrainGenerator.hpp"

class World {
    
private:
    const uint32_t xSize;
    const uint32_t ySize;
    uint32_t prevX;
    uint32_t prevY;
    float min, max;
    uint32_t worldsCount = 0;
    bool firstTime;
    
public:
    
    World(uint32_t width, uint32_t height);
    virtual ~World();
    inline uint32_t getXSize() {return xSize;};
    inline uint32_t getYSize() {return ySize;};
    inline bool getFirstTime(){bool t = firstTime; firstTime= false; return t;} 
    std::vector <std::vector<Biome> > worldMap;
    Tile getTile(uint32_t xPos, uint32_t yPos);

    void buildBiomes();
protected:    
    void generateBaseTemperature(std::vector<std::vector<int> >& temperatureMap);
    void fillMap(std::vector<std::vector<float> >& fillerMap);   
    void generateRiverSource(std::vector<std::vector<float> >& elevationMap, 
                                std::vector<std::vector<float> >& rainfallMap,
                                std::vector<std::vector<bool> > drainageMap );
    void generateRiverPath(uint32_t x, uint32_t y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    void generateErosion(uint32_t x, uint32_t y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    void fillRiver(uint32_t x, uint32_t y,
                      std::vector<std::vector<float> >& elevationMap,
                      std::vector<std::vector<bool> >& drainageMap);
    //float random(float max);
    void printMap(uint32_t mapType, std::vector<std::vector<float> >& fillerMap);
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




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
    std::vector<std::vector<float> > elevationMap;
    std::vector<std::vector<float> > rainfallMap;
    std::vector<std::vector<int> > temperatureMap;
    std::vector<std::vector<bool> > drainageMap;
    std::vector<std::vector<std::string> > riverMap;
    int worldsCount = 0;
    
public:
    
    World(int width, int height);
    virtual ~World();
    std::vector<std::vector<float> > fillerMap;    
    std::vector <std::vector<Biome> > worldMap;
    Tile getTile(int xPos, int yPos);
    void buildMaps();
    
    void buildBiomes();
    void clearMaps();
protected:    
    void generateBaseTemperature();
    void fillMap();   
    void generateRiverSource();
    void generateRiverPath(int x, int y);
    void generateErosion(int x, int y);
    void fillRiver(int x, int y);
    float random(float max);
    void printMap(int type);
    bool checkMaps();
   
    struct color{
	//v[0]=red, v[1]=green, v[2]=blue
	unsigned char v[3];
	
	color(unsigned char r, unsigned char g, unsigned char b){
		v[0]=r;
		v[1]=g;
		v[2]=b;
	}
    };
    
    color lerp(color c1, color c2, float value);

};

#endif	/* WORLD_HPP */


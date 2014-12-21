#ifndef WORLD_HPP
#define	WORLD_HPP
#include <vector>
#include <array>
#include "Biome.hpp"
#include "Tile.hpp"
#include "TerrainGenerator.hpp"

class World {
    
private:
    const int xSize;
    const int ySize;
    float min, max;
    std::vector<std::vector<float> > elevationMap;
    std::vector<std::vector<float> > rainfallMap;
    std::vector<std::vector<int> > temperatureMap;
    
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
    
    float random(float max);
    void printMap(int type);
   
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


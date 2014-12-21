#ifndef BIOME_HPP
#define	BIOME_HPP
#include "Tile.hpp"

class Biome {
    
private:
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
    float elevation;
    float rainfall;
    int temperature;
    int biomeType;
    
    
public:
    Biome();
    Biome(const Biome& orig);
    virtual ~Biome();

    void setBiomeType();
    inline int getBiomeType(){return biomeType;};
    Tile getTile();
    void debugBiome();
    inline void setElevation(float wGenElevation){elevation = wGenElevation;};
    inline void setRainfall(float wGenRainfall){rainfall = wGenRainfall;};
    inline void setTemperature(int wGenTemperature){temperature = (wGenTemperature - (elevation * 2));};
    



};

#endif	/* BIOME_HPP */


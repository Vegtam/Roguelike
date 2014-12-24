#ifndef BIOME_HPP
#define	BIOME_HPP
#include <vector>
#include "Tile.hpp"

class Biome {
    
protected:
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
    float elevation;
    float rainfall;
    int temperature;
    bool river;
    bool lake;
    int biomeType;
private:
    float sealevel = 0.0f;// 0.0f sea level
    float flood = 0.5f; // .5f flood zone
    float mount = 4.0f;// 4 mountain level
    
    float humid = 4.0f; // 4 high rainfall
    float semihumid = 2.0f; // 2 med high rainfall
    float semiarid = 0.5f; // .5 med low rainfall
    float arid = -1.0f; // .0 low rainfall
    
    int tropical = 64; // 64 Hot Temperature
    int arctic = 15; // 15 Cold Temperature 
    
    
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
    inline void setDrainage(bool wGenDrainage){river = (wGenDrainage);};
    inline void setLake(bool wGenLake){lake = (wGenLake);};
    
private:
    void displayBiome(int biomeType);
    



};

#endif	/* BIOME_HPP */


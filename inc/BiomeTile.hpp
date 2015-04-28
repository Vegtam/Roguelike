#ifndef BIOMETILE_HPP_
#define	BIOMETILE_HPP_
#include <vector>
#include <string>
#include "Tile.hpp"

class BiomeTile 
{
    
protected:
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
    float elevation;
    float rainfall;
    int temperature;
    bool river;
    bool lake;
    uint8_t biomeType;
private:
    const float sealevel = 0.0f;// 0.0f sea level
    const float flood = 0.5f; // .5f flood zone
    const float mount = 4.0f;// 4 mountain level
    
    const float humid = 4.0f; // 4 high rainfall
    const float semihumid = 2.0f; // 2 med high rainfall
    const float semiarid = 0.5f; // .5 med low rainfall
    const float arid = -1.0f; // .0 low rainfall
    
    const int tropical = 64; // 64 Hot Temperature
    const int arctic = 15; // 15 Cold Temperature

    const std::string kBiomeNames[16] = {
        "Ocean",
        "Unused1",
        "Tropical Dry Broadleaf Forest",
        "Tropical Coniferous Forest",
        "Broadleaf Forest",
        "Coniferous Forest",
        "Boreal Forest",
        "Tropical Grasslands",
        "Grasslands",
        "Flooded Grasslands",
        "Mountain",
        "Tundra",
        "Mediterranean Forest",
        "Desert",
        "Mangrove Forest",
        "Unused2"
    };
    
    
public:
    BiomeTile(){};
    virtual ~BiomeTile(){};

    void setBiomeTileType();
    inline int getBiomeTileType(){return biomeType;};
    Tile getTile();
    void debugBiomeTile();
    inline void setElevation(float wGenElevation){elevation = wGenElevation;};
    inline void setRainfall(float wGenRainfall){rainfall = wGenRainfall;};
    inline void setTemperature(int wGenTemperature){temperature = (wGenTemperature - (elevation * 2));};
    inline void setDrainage(bool wGenDrainage){river = (wGenDrainage);};
    inline void setLake(bool wGenLake){lake = (wGenLake);};
    inline float getElevation() {return elevation;};
    inline float getRainfall() {return rainfall;};
    inline int getTemperature() {return temperature;};
    inline bool getDrainage() {return river;};
    inline bool getLake() {return lake;};
    inline std::string getBiomeTypeName(){return biomeType<sizeof(kBiomeNames)/sizeof(std::string)?kBiomeNames[biomeType]:"Invalid Biome Type";};
    
private:
    
    void displayBiomeTile(int biomeType);
    



};

#endif	/* BIOME_HPP */


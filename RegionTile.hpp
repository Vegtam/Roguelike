#ifndef REGIONTILE_HPP_
#define REGIONTILE_HPP_

#include "Tile.hpp"
#include "Random.hpp"

class RegionTile
{
protected:
    int regionType;
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
private:
    void displayRegionTileType(int regionType);
    void buildOceanRegion();
    void buildTropicalMoistForestRegion();
    void buildTropicalDryForestRegion();
    void buildTropicalConiferousForestRegion();
    void buildTemperateBroadleafMixForestRegion();
    void buildTemperateConiferousForestRegion();
    void buildBorealForestRegion();
    void buildTropicalGrasslandRegion();
    void buildTemperateGrasslandRegion();
    void buildFloodedGrasslandRegion();
    void buildMontaneRegion();
    void buildTundraRegion();
    void buildMediterraneanRegion();
    void buildDesertRegion();
    void buildMangroveRegion();
    void buildDebugRegion();
    bool lake = false;
    bool forest = false;
    float elevation;
    float rainfall;
    int temperature;
    
    
    
public:
	RegionTile(){};
	virtual ~RegionTile(){};
	/* add code here for RegionTile specific stuff */
        Tile getTile();
        void setRegionTileType(int biomeType);
        
        inline void setElevation(float biomeElevation){elevation = biomeElevation + Random::get()->randFloat(4.0f) - 2.0f;};
        inline float getElevation(){return elevation;};
        
        inline void setForest(bool forested){forest = forested;};
        inline bool getForest(){return forest;};
        
};



#endif
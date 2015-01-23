#ifndef REGIONTILE_HPP_
#define REGIONTILE_HPP_

#include "Tile.hpp"


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
    
    
    
public:
	RegionTile(){};
	virtual ~RegionTile(){};
	/* add code here for RegionTile specific stuff */
        Tile getTile();
        void setRegionTileType(int biomeType);
        
};



#endif
#ifndef REGIONTILE_HPP_
#define REGIONTILE_HPP_

#include "Tile.hpp"
#include "BiomeTile.hpp"


class RegionTile: public BiomeTile
{
protected:
    int regionType;
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
private:
    void displayRegionTileType(int regionType);
    
    
    
public:
	RegionTile(){};
	virtual ~RegionTile(){};
	/* add code here for RegionTile specific stuff */
        Tile getTile();
        void setRegionTileType();
        
};



#endif
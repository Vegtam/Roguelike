#ifndef REGIONTILE_HPP_
#define REGIONTILE_HPP_

#include "Tile.hpp"
#include "BiomeTile.hpp"


class RegionTile: public BiomeTile
{
protected:
    int displayID;
    int backgroundR, backgroundG, backgroundB; //background
    int foregroundR, foregroundG, foregroundB; //foreground
private:
    
    Tile displayRegionTile();
    
    
public:
	RegionTile(){};
	virtual ~RegionTile(){};
	/* add code here for RegionTile specific stuff */
        void setRegionTileType(int regionType);
        
};



#endif
#ifndef REGION_HPP
#define	REGION_HPP

#include <vector>
#include "RegionTile.hpp"

class Region 
{
private:
	RegionTile tile;
        bool generated = false;
	/* std::vector<std::vector<Local>> localMap*/
public:
    Region(){};
    virtual ~Region(){};
    inline RegionTile& getRegionData(){return tile;};
    inline bool isGenerated(){return generated;};

    /* add code here to setup the localMap */
};

#endif	/* REGION_HPP */


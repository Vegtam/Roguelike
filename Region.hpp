#ifndef REGION_HPP
#define	REGION_HPP

#include <vector>
#include "RegionTile.hpp"

class Region 
{
private:
	RegionTile tile;
	/* std::vector<std::vector<Local>> localMap*/
public:
    Region(){};
    virtual ~Region(){};
    inline RegionTile& getTile(){return tile;};

    /* add code here to setup the localMap */
};

#endif	/* REGION_HPP */


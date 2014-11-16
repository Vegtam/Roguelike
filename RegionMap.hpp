#ifndef REGIONMAP_HPP
#define	REGIONMAP_HPP
#include "MapModel.hpp"
//The object inheritance probably doesn't support a MVC Architecture... 

class RegionMap : public MapModel {
public:
    RegionMap();
    RegionMap(const RegionMap& orig);
    virtual ~RegionMap();
private:

};

#endif	/* REGIONMAP_HPP */


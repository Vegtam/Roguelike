#ifndef REGION_HPP
#define	REGION_HPP
#include "Biome.hpp"

class Region : public Biome
{
public:
    Region();
    Region(const Region& orig);
    virtual ~Region();
private:

};

#endif	/* REGION_HPP */


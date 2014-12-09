#ifndef BIOME_HPP
#define	BIOME_HPP
#include "Tile.hpp"

class Biome {
public:
    Biome();
    Biome(const Biome& orig);
    virtual ~Biome();
    void setBiomeAttributes(int biomeType);
    Tile getTile();
    
private:
    int displayID;
    int r1, g1, b1; /*background*/
    int r2, g2, b2; /*foreground*/

};

#endif	/* BIOME_HPP */


#ifndef BIOME_HPP
#define	BIOME_HPP
#include "Tile.hpp"

class Biome {
public:
    Biome();
    Biome(const Biome& orig);
    virtual ~Biome();
    int elevation;
    void setBiomeAttributes(int biomeType);
    Tile getTile();
    
private:
    int displayID;
    int backgroundR, backgroundG, backgroundB; /*background*/
    int foregroundR, foregroundG, foregroundB; /*foreground*/

};

#endif	/* BIOME_HPP */


#ifndef BIOME_HPP
#define	BIOME_HPP

class Biome {
public:
    Biome();
    Biome(const Biome& orig);
    virtual ~Biome();
    void setDisplayID(int biomeType);
    int getDisplayID();
private:
    int displayID;

};

#endif	/* BIOME_HPP */


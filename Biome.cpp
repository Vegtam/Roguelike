#include "Biome.hpp"

/*
  
    01 Tropical and subtropical moist broadleaf forests (tropical and subtropical, humid)
    02 Tropical and subtropical dry broadleaf forests (tropical and subtropical, semihumid)
    03 Tropical and subtropical coniferous forests (tropical and subtropical, semihumid)
    04 Temperate broadleaf and mixed forests (temperate, humid)
    05 Temperate coniferous forests (temperate, humid to semihumid)
    06 Boreal forests/taiga (subarctic, humid)
    07 Tropical and subtropical grasslands, savannas, and shrublands (tropical and subtropical, semiarid)
    08 Temperate grasslands, savannas, and shrublands (temperate, semiarid)
    09 Flooded grasslands and savannas (temperate to tropical, fresh or brackish water inundated)
    10 Montane grasslands and shrublands (alpine or montane climate)
    11 Tundra (Arctic)
    12 Mediterranean forests, woodlands, and scrub or sclerophyll forests (temperate warm, semihumid to semiarid with winter rainfall)
    13 Deserts and xeric shrublands (temperate to tropical, arid)
    14 Mangrove (subtropical and tropical, salt water inundated)

 */

Biome::Biome() {
}

Biome::Biome(const Biome& orig) {
}

Biome::~Biome() {
}

void Biome::setBiomeAttributes(int biomeType)
{
        switch(biomeType)
    {
            case 0: /* ocean */
                
                displayID = 247; /* ~ */
                
                /* light blue green */
                r1 = 0;
                g1 = 225;
                b1 = 225;
                
                /* dark blue*/            
                r2 = 0;
                g2 = 255;
                b2 = 255;

                break;
        
            case 1: /* Tropical moist forests */
                
                displayID = 5; /* deciduous tree */
                
                /* dark green */
                r1 = 0;
                g1 = 100;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 2: /* Tropical dry forests */
                
                displayID = 5; /* deciduous tree */
                
                /* dark brown */
                r1 = 125;
                g1 = 75;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 3: /* Tropical coniferous forests */
                
                displayID = 6; /* coniferous tree */
                
                /* dark brown */
                r1 = 125;
                g1 = 75;
                b1 = 0;
                
                /* dark green */
                r2 = 0;
                g2 = 100;
                b2 = 0;
                
                break;
                
            case 4: /* Temperate broadleaf and mixed forests */
                
                displayID = 23; /* coneiduous tree (yes I made that up) */
                
                /* medium brown */
                r1 = 150;
                g1 = 100;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 5: /* Temperate coniferous forests */
                
                displayID = 6; /* coniferous tree */
                
                /* medium brown */
                r1 = 150;
                g1 = 100;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 6: /*  Boreal forests/taiga */ 
                
                displayID = 6; /* coniferous tree */ 
                
                /* light green */
                r1 = 0;
                g1 = 200;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 7: /* Tropical grasslands, savannas, and shrublands */
                
                displayID = 170; /* grass curled to left */ 
                
                /* dark brown */
                r1 = 125;
                g1 = 75;
                b1 = 0;
                
                /* dark green */
                r2 = 0;
                g2 = 100;
                b2 = 0;
                
                break;
                
            case 8: /* Temperate grasslands, savannas, and shrublands */
                
                displayID = 170; /* grass curled to left */ 
                
                /* medium brown */
                r1 = 150;
                g1 = 100;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 9: /* Flooded grasslands and savannas */
                
                displayID = 170; /* grass curled to left */
                
                /* medium blue */
                r1 = 0;
                g1 = 125;
                b1 = 255;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 10: /* Montane grasslands and shrublands */
                
                displayID = 170;
                
                /* light brown */
                r1 = 200;
                g1 = 175;
                b1 = 0;
                
                /* medium green */
                r2 = 0;
                g2 = 150;
                b2 = 0;
                
                break;
                
            case 11: /* Tundra (Arctic) */
                
                displayID = 236; /* filled small circle */
                
                /* light brown */
                r1 = 200;
                g1 = 175;
                b1 = 0;
                
                /* gray */
                r2 = 175;
                g2 = 175;
                b2 = 125;
                
                break;
                
            case 12: /* Mediterranean forests */
                
                displayID = 23; /*coneiduous tree */
                
                /* medium green */
                r1 = 0;
                g1 = 150;
                b1 = 0;
                
                /* light green */
                r2 = 0;
                g2 = 200;
                b2 = 0;
                
                break;
                
            case 13: /* Deserts */
                
                displayID = 247; /* ~ */
                
                /* light brown */
                r1 = 200;
                g1 = 175;
                b1 = 0;
                
                /* orange */
                r2 = 255;
                g2 = 175;
                b2 = 0;
                
                break;
                
            case 14: /* Mangrove */
                
                displayID = 5;
                
                /* light blue */
                r1 = 0;
                g1 = 175;
                b1 = 200;
                
                /* dark green */
                r2 = 0;
                g2 = 100;
                b2 = 0;        
                
                
    }
    
}
 
Tile Biome::getTile()
{
    return Tile(displayID, al_map_rgb(r1,g1,b1), al_map_rgb(r2,g2,b2));
}


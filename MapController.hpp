#ifndef MAPCONTROLLER_HPP
#define	MAPCONTROLLER_HPP
#include "allegro5/allegro.h"

class MapController {
public:
    MapController();
    MapController(const MapController& orig);
    virtual ~MapController();
    void drawMap(int x, int y);
private:

};

#endif	/* MAPCONTROLLER_HPP */


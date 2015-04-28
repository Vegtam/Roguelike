#ifndef BIOMEVIEW_HPP
#define BIOMEVIEW_HPP

#include <stdint.h>
#include <vector>

#include "Biome.hpp"
#include "View.hpp"
#include "TextPane.hpp"
#include "TileMap.hpp"
#include "Model.hpp"
#include "ResourceSet.hpp"
#include "Font.hpp"
#include "Displayable.hpp"


//Copied from WorldView
class BiomeView : public View
{
    
private:
    TextPane localeInfo;
    TextPane commandInfo;
    TileMap localeDisplay;
    bool drawn = false;
    bool bound = true;
    bool rebound = false;
    std::vector<Region*> currentRegions;
    std::vector<Displayable*> drawList;
    int pseudoX;
    int pseudoY;
    uint32_t viewWindowX;
    uint32_t viewWindowY;

    virtual DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
    void redraw(int xPos, int yPos);
    
    
public:
    const static uint32_t kMapWidth = 33;
    const static uint32_t kMapHeight = 33;
    
    BiomeView(){};
    BiomeView(Model* md, 
		      ResourceSet<Font>* fs, 
		      ResourceSet<TileSet>* ts):View(md, fs, ts, NULL),
                                        currentRegions((Biome::kMapWidth*3)*
                                                       (Biome::kMapHeight*3)),
                                        viewWindowX(0),
                                        viewWindowY(0){};
	virtual bool init();
	virtual ~BiomeView(){/*drawlist and parent destructor get called automatically*/};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();


};

#endif	/* BIOMEVIEW_HPP */


#ifndef WORLDVIEW_HPP_
#define WORLDVIEW_HPP_

#include <vector>
#include <allegro5/allegro.h>

#include "Displayable.hpp"
#include "View.hpp"
#include "Font.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include "TextPane.hpp"
#include "ResourceSet.hpp"
#include "Model.hpp"
#include "BiomeView.hpp"

class WorldView : public View
{
private:
        
	TextPane biomeInfo;
	TileMap biomeDisplay;
        
	std::vector<Displayable*> drawList;
	virtual DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
public:
	WorldView(){};
	WorldView(Model* md, 
		      ResourceSet<Font>* fs, 
		      ResourceSet<TileSet>* ts):View(md, fs, ts, NULL){};
	virtual bool init();
	virtual ~WorldView(){/*drawlist and parent destructor get called automatically*/};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();
};

#endif
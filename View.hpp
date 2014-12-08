#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <vector>
#include <allegro5/allegro.h>
#include "Model.hpp"
#include "Displayable.hpp"
#include "ResourceSet.hpp"
#include "Font.hpp"
#include "TileSet.hpp"
#include "Image.hpp"

enum class DefinedViews
{
	TITLE_VIEW,
	WORLD_VIEW,
	BIOME_VIEW,
	LOCAL_VIEW,
	STATUS_VIEW,
	SETTINGS_VIEW,
	CREDITS_VIEW,
	QUIT_VIEW,
};

/* View is really the controller in the MVC architecture, it ties together the world model,
event handling and the elements to be drawn on each screen */

class View
{
protected:
	Model* model;
	ResourceSet<Font>* fontset;
	ResourceSet<TileSet>* tileset;
	ResourceSet<Image>* imageset;
	bool is_init;
public:
	View(): model(NULL), fontset(NULL), tileset(NULL), imageset(NULL), is_init(false) {};
	View(Model* md, 
		 ResourceSet<Font>* fs, 
		 ResourceSet<TileSet>* ts, 
		 ResourceSet<Image>* is):model(md), fontset(fs), tileset(ts), imageset(is), is_init(false){};
	virtual ~View() {/*pointers are not owned by this class so do nothing */};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev) = 0;
	virtual std::vector<Displayable*>& draw() = 0;
	
};

#endif
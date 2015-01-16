#ifndef BIOMEVIEW_HPP
#define BIOMEVIEW_HPP
#include "WorldView.hpp"
#include "View.hpp"
//Copied from WorldView
class BiomeView : public View
{
    
private:
    TextPane localeInfo;
    TileMap localeDisplay;
    bool drawn = false;
    std::vector<Displayable*> drawList;
    virtual DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
    void redraw(int xPos, int yPos);
    
    
public:
    BiomeView(){};
    BiomeView(Model* md, 
		      ResourceSet<Font>* fs, 
		      ResourceSet<TileSet>* ts):View(md, fs, ts, NULL){};
	virtual bool init();
	virtual ~BiomeView(){/*drawlist and parent destructor get called automatically*/};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();


};

#endif	/* BIOMEVIEW_HPP */


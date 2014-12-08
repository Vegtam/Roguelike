#ifndef TEXTPANE_HPP_
#define TEXTPANE_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <string>
#include <vector>

#include "Displayable.hpp"

class TextPane: public Displayable
{
private:
	ALLEGRO_FONT* font;

	ALLEGRO_COLOR backg; //clear bitmap color
	ALLEGRO_COLOR foreg; //text color
	
	std::vector<std::string> text;
	
	uint32_t xpos; // unscaled x position of pane
	uint32_t ypos; // unscaled y position of pane

	uint32_t wind_w; // unscaled width in pixels of pane
	uint32_t wind_h; // unscaled height in pixels of pane
	
	ALLEGRO_BITMAP* backing_bmap; /* colored bitmap of current tiles */

	bool dirty;
	bool is_init;
public:
	TextPane();
	bool init(ALLEGRO_FONT* fnt, uint32_t x, uint32_t y, uint32_t w, uint32_t h);
	bool write(std::string);

	inline void setFore(ALLEGRO_COLOR clr) {dirty = true; foreg = clr;};
	inline void setBack(ALLEGRO_COLOR clr) {dirty = true; backg = clr;};

	bool render();

	/* Displayable requirement */
	virtual void draw(float xscale, float yscale);

};

#endif
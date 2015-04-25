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
	
	ALLEGRO_BITMAP* backing_bmap; /* Colored bitmap of current text */

	bool dirty;
	bool is_init;
protected:
	inline bool isInit() {return is_init;};
	inline ALLEGRO_COLOR getFore() {return foreg;};
	inline ALLEGRO_COLOR getBack() {return backg;};
public:
	TextPane();
	virtual bool init(ALLEGRO_FONT* fnt, uint32_t x, uint32_t y, uint32_t w, uint32_t h);
	bool write(std::string);

	inline void setFore(ALLEGRO_COLOR clr) {dirty = true; foreg = clr;};
	inline void setBack(ALLEGRO_COLOR clr) {dirty = true; backg = clr;};
	inline uint32_t getX() {return xpos;};
	inline uint32_t getY() {return ypos;};
	inline uint32_t getWidth() {return wind_w;};
	inline uint32_t getHeight() {return wind_h;};

	bool render();

	/* Displayable requirement */
	virtual void draw();

};

#endif
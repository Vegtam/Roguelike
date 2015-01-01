#ifndef TEXTENTRY_HPP_
#define TEXTENTRY_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <string>
#include <stdint.h>
#include "TextPane.hpp"

class TextEntry: public TextPane
{
private:
	std::vector<char> current;
	bool inFocus;
	uint32_t maxChars;
	int32_t cursorPos;
	void handleKeyPress(ALLEGRO_EVENT* ev);
public:
	TextEntry():TextPane(), 
	             current(), 
	             inFocus(false), 
	             maxChars(0), 
	             cursorPos(0){};
	
	inline void setInFocus(bool val){inFocus = val;};
	inline bool getInFocus() {return inFocus;};
	inline std::string getCurrent() {return std::string(current.begin(),current.end());};

	virtual bool init(ALLEGRO_FONT* fnt, uint32_t x, uint32_t y, uint32_t w);
	void handleEvent(ALLEGRO_EVENT* ev);
	virtual void draw(float xscale, float yscale);
};

#endif
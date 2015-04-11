#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <string>
#include "Displayable.hpp"
#include "Font.hpp"

class Text: public Displayable
{
private:
	Font& font;
	ALLEGRO_COLOR color;
	int32_t align;
	uint32_t x;
	uint32_t y;
	std::string text;
	uint32_t size;
	constexpr static uint32_t kDefaultSize = 8;
public:
	Text () = delete;
	Text (Font& fnt, ALLEGRO_COLOR clr, std::string txt): Text(fnt, clr, ALLEGRO_ALIGN_LEFT,0,0, Text::kDefaultSize, txt){}; 
	Text (Font& fnt, std::string txt);
	Text (Font& fnt, 
		  ALLEGRO_COLOR clr, 
		  int32_t alignment, 
		  uint32_t xpos, 
		  uint32_t ypos,
		  uint32_t sz, 
		  std::string txt):font(fnt),color(clr), align(alignment), x(xpos),y(ypos),size(sz),text(txt){};;
	inline void setSize(uint32_t sz) {size = sz;};
	inline void setColor(ALLEGRO_COLOR clr){ color=clr; };
	inline void setAlign(int32_t algn) { align = algn; };
	inline void setPos(uint32_t xpos, uint32_t ypos){ x=xpos; y=ypos; };
	virtual void draw();
	virtual ~Text(){};
};

#endif
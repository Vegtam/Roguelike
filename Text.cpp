#include "Text.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <string>
#include <math.h>

Text::Text (Font& fnt, std::string txt): font(fnt), align(ALLEGRO_ALIGN_LEFT), text(txt), x(0), y(0), size(Text::kDefaultSize)
{
	color = al_map_rgb(0,0,0); //default is black
}

void Text::draw(float xscale, float yscale)
{
	//calculate diagonal scale factor
	float scale = sqrt(xscale*xscale+yscale*yscale);
	al_draw_text(font.get((int)(size*scale)),
		         color,
		         xscale*(float)x,
		         yscale*(float)y,
		         align,
		         text.c_str());
}
#include "Text.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <string>
#include <math.h>

Text::Text (Font& fnt, std::string txt): font(fnt), 
										 align(ALLEGRO_ALIGN_LEFT), 
										 text(txt), 
										 x(0), 
										 y(0), 
										 size(Text::kDefaultSize)
{
	color = al_map_rgb(0,0,0); //default is black
}

void Text::draw()
{
	/** @todo Currently, if text is too close together, scaling will lead to 
	overlapping text for wide/short windows. Need to look into heirarchical 
	positioning based on bounding boxes*/
	//calculate diagonal scale factor
	al_draw_text(font.get((int)(size)),
		         color,
		         (float)x,
		         (float)y,
		         align,
		         text.c_str());
}
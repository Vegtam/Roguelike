#include <iostream>
#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "TextPane.hpp"

TextPane::TextPane():font(NULL), 
                     text(), 
                     xpos(0), 
                     ypos(0), 
                     wind_w(0), 
                     wind_h(0), 
                     is_init(false), 
                     dirty(true),
                     backing_bmap(NULL)
{
	backg=al_map_rgb(0,0,0); //background defaults to black
	foreg=al_map_rgb(255,255,255); //foreground defaults to white
}

bool TextPane::init(ALLEGRO_FONT* fnt, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	bool result = false;
 
	if( fnt )
	{
		int height = al_get_font_line_height (fnt);
		if( h >= height && w >= height)
		{
			font = fnt;
			text.clear();
			xpos = x;
			ypos = y;
			wind_w = w;
			wind_h = h;
			result = dirty = is_init = true;
		}
	}
	return result;
}
bool TextPane::write(std::string txt)
{
	bool result = false;
	if(is_init)
	{
		int width = al_get_text_width(font, txt.c_str());
		/* split the text into multiple lines if necessary */
		if( width > wind_w)
		{
			std::string tmp;
			int j = 0;
			for (int i = 0; i < txt.size(); i+=j)
			{
				j = txt.size()-i;
				/* find a chunk of the string that fits in the window */
				while( al_get_text_width(font, txt.substr(i,j).c_str()) >wind_w  && 
					   j > 0)
				{
					j--;
				}
				/* make sure spaces end up on the left rather than the right
				but only if we haven't reached the end of the string */
				if( i+j <txt.size())
				{
					while( txt[i+j-1] != ' ' && j >0 )
					{ 
						j--;
					}
				}
				
				text.push_back(txt.substr(i,j));
			}	
		}
		else
		{
			text.push_back(txt);
		}
		int height = al_get_font_line_height(font);
		/* erase from the beginning of text until the text fits in the window */
		while( height * text.size() > wind_h)
		{
			text.erase(text.begin());
		}
		result = dirty = true;
	}
	return result;
}

bool TextPane::render()
{
	ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
	
	if (is_init && dirty)
	{
		if ( backing_bmap == NULL)
		{
			al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
			backing_bmap = al_create_bitmap(wind_w, wind_h);
		}
		if( backing_bmap )
		{
			al_set_target_bitmap(backing_bmap);
			al_clear_to_color(backg);

			uint32_t y = 0;
			int height = al_get_font_line_height(font);
			for (auto& str :text)
			{
				/* for now text panes only support left aligned text */
				al_draw_text(font,
		                     foreg,
		                     0,
		                     y,
		                     ALLEGRO_ALIGN_LEFT,
		                     str.c_str());
				y+=height;
			}
			dirty = false;
		}
	}
	al_set_target_bitmap(old_target);
	return !dirty;
}

void TextPane::draw(float xscale, float yscale)
{
	if (is_init && backing_bmap)
	{
		/* no flags */
		al_draw_scaled_bitmap(backing_bmap, 
			                  0, 
		    	              0,
		        	          al_get_bitmap_width(backing_bmap),
		            	      al_get_bitmap_height(backing_bmap),
		                	  (float)xpos*xscale,
		                  	  (float)ypos*yscale,
		                  	  (float)wind_w*xscale,
		                  	  (float)wind_h*yscale,
		                  	  0);
	}
}
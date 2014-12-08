#include <stdint.h>
#include <allegro5/allegro.h>

#include "Image.hpp"

bool Image::init(uint32_t xpos, uint32_t ypos, int32_t w, int32_t h )
{
	bool result = false;
	if(!is_init)
	{
		x = xpos;
		y = ypos;
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		img = al_load_bitmap(al_path_cstr(img_path,ALLEGRO_NATIVE_PATH_SEP));
		if( img != NULL)
		{
			wind_w = w==-1?al_get_bitmap_width(img):w;
			wind_h = h==-1?al_get_bitmap_height(img):h;
			result = is_init = true;
		}
	}
	return result;
}

Image::~Image()
{
	al_destroy_path(img_path);
	if (is_init)
	{
		al_destroy_bitmap(img);
		is_init = false;
	}
}

void Image::draw(float xscale, float yscale)
{
	if (is_init && img)
	{
		/* no flags */
		al_draw_scaled_bitmap(img, 
			                  0, 
		    	              0,
		        	          al_get_bitmap_width(img),
		            	      al_get_bitmap_height(img),
		                	  (float)x*xscale,
		                  	  (float)y*yscale,
		                  	  (float)wind_w*xscale,
		                  	  (float)wind_h*yscale,
		                  	  0);
	}
}
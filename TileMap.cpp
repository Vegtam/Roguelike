#include <stdint.h>

#include <iostream>

#include "TileSet.hpp"
#include "TileMap.hpp"

bool TileMap::init(uint32_t xpos, 
		      uint32_t ypos,
		      uint32_t w,
		      uint32_t h,
		      uint32_t tiles_w,
		      uint32_t tiles_h,
		      TileSet* tls)
{
	bool result = false;
	if( w && h && tiles_w && tiles_h)
	{
		x = xpos;
		y = ypos;
		wind_w = w;
		wind_h = h;
		map_w = tiles_w;
		map_h = tiles_h;
		t_set = tls;
		tiles.resize(map_w * map_h);
		result = dirty = is_init = true;
	}

	return result;
}

ALLEGRO_BITMAP* TileMap::getColoredTile(Tile t)
{
	ALLEGRO_BITMAP* old_target = al_get_target_bitmap();

	if(coloredTileCache.find(t) == coloredTileCache.end())
	{
		al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
		ALLEGRO_BITMAP* bmap = al_create_bitmap(t_set->getTileWidth(), t_set->getTileHeight());
		if( bmap )
		{
			al_lock_bitmap(bmap,ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_WRITEONLY);
			al_set_target_bitmap(bmap);
			al_clear_to_color(t.getBack());

			uint8_t r = 0;
			uint8_t g = 0;
			uint8_t b = 0;
			uint8_t o_r = 0;
			uint8_t o_g = 0;
			uint8_t o_b = 0; 

			al_unmap_rgb(t.getFore(),&o_r,&o_g,&o_b);
			ALLEGRO_BITMAP* tile = t_set->get(t.getIndex());
			al_lock_bitmap(tile,ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
			for(uint32_t i = 0; i<t_set->getTileWidth();i++)
			{
				for(uint32_t j = 0; j< t_set->getTileHeight(); j++)
				{
					ALLEGRO_COLOR pix = al_get_pixel(tile,i,j);
					al_unmap_rgb(pix,&r,&g,&b);
					// magenta is the background color 255, 0, 255 in rgb
					if(r==255 && b == 255 && g == 0)
					{
						pix = t.getBack();
					}
					else
					{
						pix = al_map_rgb((r*o_r)/256,(g*o_g)/256,(b*o_b)/256);
					}
					al_draw_pixel(i, j, pix);
				}
			}
			al_unlock_bitmap(tile);
			al_unlock_bitmap(bmap);
			coloredTileCache.emplace(t, bmap);
		}
		else
		{
			al_set_target_bitmap(old_target);
			return NULL;
		}
	}
	al_set_target_bitmap(old_target);
	return coloredTileCache[t];
}

bool TileMap::render()
{
	bool firstTime = false;
	ALLEGRO_LOCKED_REGION *bmap, *tl;
	ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
	if (dirty)
	{
		if(backing_bmap==NULL)
		{
			al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP|ALLEGRO_FORCE_LOCKING);
			backing_bmap = al_create_bitmap(map_w*t_set->getTileWidth(), 
										    map_h*t_set->getTileHeight());
			firstTime = true;
		}
		if(backing_bmap)
		{
			uint32_t index = 0;
			/* set the target for draw operations to the backing bitmap */
			
			/* @todo consider checking this lock */
			if( (bmap = al_lock_bitmap(backing_bmap,ALLEGRO_PIXEL_FORMAT_ANY,ALLEGRO_LOCK_WRITEONLY)) == NULL)
			{
				std::cout <<"Error locking bitmap"<<std::endl;
				al_set_target_bitmap(old_target);
				return false;
			}

			al_set_target_bitmap(backing_bmap);
			//al_hold_bitmap_drawing(true);
			
			if (firstTime)
			{
				al_clear_to_color(al_map_rgb(255,255,255));	
			}

			for (auto& tile: tiles)
			{
				float tile_x = (index%map_w)*t_set->getTileWidth();
				float tile_y = (index/map_w)*t_set->getTileHeight();
				ALLEGRO_BITMAP* t = getColoredTile(tile);
				if( t )
				{
					al_draw_bitmap(t,tile_x,tile_y, 0);
				}
				tile.clearDirty();
                index++;
			}
			al_unlock_bitmap(backing_bmap);
			//al_hold_bitmap_drawing(false);
			dirty = false;
		}

	}
	al_set_target_bitmap(old_target);
	return !dirty;
}

void TileMap::draw(float xscale, float yscale)
{
	if (is_init && backing_bmap)
	{
		/* no flags */
		al_draw_scaled_bitmap(backing_bmap, 
			                  0, 
		    	              0,
		        	          al_get_bitmap_width(backing_bmap),
		            	      al_get_bitmap_height(backing_bmap),
		                	  (float)x*xscale,
		                  	  (float)y*yscale,
		                  	  (float)wind_w*xscale,
		                  	  (float)wind_h*yscale,
		                  	  0);
	}
}
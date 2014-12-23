#include <stdint.h>
#include <allegro5/allegro.h>

#include "TileSet.hpp"

bool TileSet::init(uint32_t w, uint32_t h)
{
	bool result = false;
	int32_t base_w = 0;
	int32_t base_h = 0;
	if(!is_init)
	{
		al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
		tileset = al_load_bitmap(al_path_cstr(tileset_path,ALLEGRO_NATIVE_PATH_SEP));
		if(tileset)
		{
			base_w = al_get_bitmap_width(tileset);
			base_h = al_get_bitmap_height(tileset);
			if( w > 0 && 
				h > 0 &&
				base_w % w == 0 &&
				base_h % h == 0)
			{
				/* the bitmap is an even number of tiles
				   so we are good*/
				tile_w = w;
				tile_h = h;
				result = is_init = true;
			}
		}
	}
	return result;
}

TileSet::~TileSet()
{
	al_destroy_path(tileset_path);
	if(is_init)
	{
		is_init=false;
		al_destroy_bitmap(tileset);

		for(auto& kv : tiles)
		{
			al_destroy_bitmap(kv.second);
		}
	}
}

uint32_t TileSet::numTiles()
{
	uint32_t num = 0;
	
	if (is_init)
	{
		int32_t base_w = al_get_bitmap_width(tileset);
		int32_t base_h = al_get_bitmap_height(tileset);

		num = (base_w/tile_w)*(base_h/tile_h);
	}
	return num;
}

ALLEGRO_BITMAP* TileSet::get(uint32_t index)
{
	ALLEGRO_BITMAP* bmap = NULL;
	if (is_init && index < numTiles())
	{
		if(tiles.find(index) == tiles.end())
		{
			int32_t base_w = al_get_bitmap_width(tileset);
			int32_t base_h = al_get_bitmap_height(tileset);
			
			/*
			base_w = width in pixels of the parent bitmap
			base_h = height in pixels of the parent bitmap
			tile_w = width in pixels of a tile. base_w is guaranteed evenly 
			         divisible by tile_w
			tile_h = height in pixels of a tile. base_h is guaranteed evenly
			         divisible by tile_h
			x and y are the pixel coordinates of the upper left corner of the
			tile we want. 
			Remember:
			 0,0            is the upper left of the bitmap
			 0, base_w      is the upper right of the bitmap
			 base_h, 0      is the lower left of the bitmap
			 base_h, base_w is the lower right of the bitmap

			index is the tile number, are numbered left to right, top to bottom

			index 0 is the upper left most tile with coordinates 0,0

			the lower right tile is the last tile with coordinates
			base_w - tile_w, base_h-tile_h

			because index is less than numTiles, x and y are guaranteed
			to be valid
			*/
			int32_t x = (index%(base_w/tile_w))*tile_w;
			int32_t y = (index/(base_w/tile_w))*tile_h;

			/* create the sub-bitmap and store it in the map */
			tiles.emplace(index, 
				          al_create_sub_bitmap(tileset, x,y, tile_w, tile_h));
		
		}
		bmap = tiles[index];
	}
	return bmap;
}
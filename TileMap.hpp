#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <stdint.h>
#include <allegro5/allegro.h>
#include <vector>
#include <map>

#include "Tile.hpp"
#include "TileSet.hpp"
#include "Displayable.hpp"

/*
Tile Map is a data structure that lets us create a rectangle of an integral number
of Tiles from a TileSet.

x,y, wind_w and wind_h describe the bounding box that the Tile Map will occupy 
on a default window

backing_bmap is a bitmap of width map_w*t_set.getTileWidth() and 
height map_h*t_set.getTileHeight(). The vector tiles is sized so that it always
contains enough space to describe the tile at each location in the map.

The render() operation will re draw the whole backing bit map based on the tiles vector
if the the tile vector has been changed.

The draw() operation will scale the backing bit map and draw it the to the current 
display

*/
class TileMap: public Displayable
{
private:
	uint32_t x; /* x coordinate of TileMap draw location (upper left, unscaled) */
	uint32_t y; /* y coordinate of TileMap draw location (upper left, unscaled) */

	uint32_t wind_w; /* Unscaled width in pixels that this tilemap can take up on a window */
	uint32_t wind_h; /* Unscaled height in pixels that this tilemap can take up on a window */

	uint32_t back_w; /* width of backing bitmap in pixels */
	uint32_t back_h; /* height of backing bitmap in pixels */

	uint32_t map_w; /* width of map in tiles */
	uint32_t map_h; /* height of map in tiles */
	
	TileSet* t_set; /* Tileset from which to get tile bitmaps */
	ALLEGRO_BITMAP* backing_bmap; /* colored bitmap of current tiles */
	std::vector<Tile> tiles; /* set of tiles in tile map */
	std::map<Tile, ALLEGRO_BITMAP*> coloredTileCache;

	bool is_init;
	bool dirty; /* flag to indicate need to re-render backing bitmap */

	ALLEGRO_BITMAP* getColoredTile(Tile);
public:
	TileMap():x(0),
	          y(0), 
	          wind_w(0), 
	          wind_h(0), 
	          back_w(0), 
	          back_h(0), 
	          map_w(0), 
	          map_h(0),
	          backing_bmap(NULL), 
	          is_init(false),
	          t_set(NULL), 
	          dirty(true),
	          coloredTileCache(){};

	bool init(uint32_t xpos, 
		      uint32_t ypos,
		      uint32_t w,
		      uint32_t h,
		      uint32_t tiles_w,
		      uint32_t tiles_h,
		      TileSet* tls);

	inline std::vector<Tile>* getTiles() { return is_init?&tiles:NULL; };
	inline void setDirty() {dirty = true;};

	virtual ~TileMap();

	bool render();

	/* Displayable requirement */
	virtual void draw();
};

#endif
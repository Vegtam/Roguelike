#ifndef TILESET_HPP_
#define TILESET_HPP_

#include <allegro5/allegro.h>
#include <stdint.h>
#include <map>

class TileSet
{
private:
	ALLEGRO_PATH* tileset_path;
	ALLEGRO_BITMAP* tileset;
	uint32_t tile_w;
	uint32_t tile_h;
	std::map<uint32_t, ALLEGRO_BITMAP*> tiles;
	bool is_init;
public:
	TileSet(): tileset_path(NULL), 
	           tileset(NULL), 
	           tile_w(0), 
	           tile_h(0), 
	           is_init(false){};
	TileSet(ALLEGRO_PATH* path):tileset_path(path), 
	                            tileset(NULL), 
	                            tile_w(0), 
	                            tile_h(0),
	                            is_init(false){};
	virtual ~TileSet();
	bool init(uint32_t w, uint32_t h);
	uint32_t numTiles();
	inline uint32_t getTileWidth() {return tile_w;};
	inline uint32_t getTileHeight() {return tile_h;};
	ALLEGRO_BITMAP* get(uint32_t index);
};

#endif
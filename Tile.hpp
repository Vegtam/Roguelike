#ifndef TILE_HPP_
#define TILE_HPP_

#include <stdint.h>
#include <allegro5/allegro.h>

/* Tile is a simple abstraction to tie a tile index and color together
   Tiles are not displayable on their own. They aren't tied to a Tileset
   and thus don't have bitmaps.

   To draw tiles, make a TileMap and put Tiles into it. Then draw the Tilemap

   If we want to add properties to tiles later we should do it by adding some generic
   opaque data here rather than subclassing. (This is called aggregation rather than
   inheritance)

   To prevent subclassing, class is marked final.  This is a requirement of TileMap.
*/
class Tile final
{
private:
	uint32_t index;
	ALLEGRO_COLOR back;
	ALLEGRO_COLOR fore;
	bool dirty;
	int compareColor(const ALLEGRO_COLOR& lhs, const ALLEGRO_COLOR& rhs) const ;
public:
	Tile(): Tile(0){};
	Tile(uint32_t index): Tile(index, al_map_rgb(0,0,0),al_map_rgb(1,1,1)){};
	Tile(uint32_t idx, ALLEGRO_COLOR bck, ALLEGRO_COLOR fr): index(idx), back(bck), fore(fr),dirty(true){};
	virtual ~Tile(){};
	inline uint32_t getIndex() {return index;};
	inline ALLEGRO_COLOR getBack() {return back;};
	inline ALLEGRO_COLOR getFore() {return fore;};
	inline void setIndex(uint32_t idx) {dirty = true; index = idx;};
	inline void setBack(ALLEGRO_COLOR clr) {dirty = true; back=clr;};
	inline void setFore(ALLEGRO_COLOR clr) {dirty = true; fore=clr;};
	inline bool isDirty(){return dirty;};
	inline void clearDirty() {dirty = false;};
	bool operator<(Tile const& rhs) const;
};

#endif
#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <stdint.h>
#include <string>

#include <allegro5/allegro.h>
#include "Displayable.hpp"


class Image: public Displayable
{
private:
	ALLEGRO_BITMAP* img;
	ALLEGRO_PATH* img_path;
	uint32_t x; /* x coordinate of TileMap draw location (upper left, unscaled) */
	uint32_t y; /* y coordinate of TileMap draw location (upper left, unscaled) */

	uint32_t wind_w; /* Unscaled width in pixels that this tilemap can take up on a window */
	uint32_t wind_h; /* Unscaled height in pixels that this tilemap can take up on a window */

	bool is_init;
public:
	Image(): img_path(NULL), img(NULL), x(0), y(0), wind_w(0), wind_h(0), is_init(false){};
	Image(ALLEGRO_PATH* path):img_path(path), img(NULL), x(0), y(0), wind_w(0), wind_h(0), is_init(false) {};
	virtual ~Image();
	bool init(uint32_t xpos=0, uint32_t ypos=0, int32_t w=-1, int32_t h=-1 );
	/* Displayable requirement */
	virtual void draw(float xscale, float yscale);
};

#endif
#ifndef FONT_HPP_
#define FONT_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <map>

class Font
{
private:
	ALLEGRO_PATH* font_path;
	std::map<uint32_t, ALLEGRO_FONT*> fonts;
public:
	Font(){};
	Font(ALLEGRO_PATH* fontPath):font_path(fontPath){};
	virtual ~Font();
	ALLEGRO_FONT* get(uint32_t size);
};

#endif
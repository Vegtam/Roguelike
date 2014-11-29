#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdint.h>
#include <map>

#include "Font.hpp"

Font::~Font()
{
	al_destroy_path(font_path);
	for (std::map<uint32_t,ALLEGRO_FONT*>::iterator it = fonts.begin();
		 it != fonts.end();
		 it++)
	{
		al_destroy_font(it->second);
	}
}

ALLEGRO_FONT* Font::get(uint32_t size)
{
	/* if we don't have the font loaded at this size yet then load it */
	if(fonts.find(size) == fonts.end())
	{
		// We don't currently support font flags
		fonts[size] = al_load_font(al_path_cstr(font_path,ALLEGRO_NATIVE_PATH_SEP),
			                       size, 
			                       0);
	}
	/* returns null if the font fails to load */
	return fonts[size];
}
#include <string>
#include <allegro5/allegro.h>
#include "FontSet.hpp"
#include "Font.hpp"


FontSet::FontSet(std::string dir)
{
	directory = al_create_path_for_directory(dir.c_str());
}

FontSet::~FontSet()
{
	al_destroy_path(directory);
}

Font& FontSet::getFont(std::string name)
{
	if(fonts.find(name) == fonts.end())
	{
		ALLEGRO_PATH* fullpath = al_create_path(name.c_str());
		if(al_rebase_path(directory, fullpath))
		{
			fonts.emplace(name,fullpath);
		}
		//@todo figure out what to do for else case
	}
	return fonts[name];
}
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "Allegro.hpp"

bool Allegro::init()
{
	bool result = al_init();
	if(result)
	{
		al_init_font_addon();
		result = al_init_ttf_addon();
	}
	if(result)
	{
		result = al_init_image_addon();
	}
	if(result)
	{
		result = al_init_primitives_addon();
	}
	
	is_init = result;
	
	return result;
}

Allegro::~Allegro()
{
	is_init = false;
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_uninstall_system(); //opposite of al_init()
}
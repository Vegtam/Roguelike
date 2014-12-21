#include <tuple>
#include <allegro5/allegro.h>

#include "Model.hpp"
Model::Model():world(65,65)
{
	themeFont = al_map_rgb(210,15,0); /* blood red */
	themeBackground = al_map_rgb(255,255,0); /* yellow */
	worldTileSet = std::make_tuple("Anikki_sq_10x10.bmp",10,10);
	player.Init();
}
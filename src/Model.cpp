#include <tuple>
#include <allegro5/allegro.h>

#include "Model.hpp"
Model::Model():world(65,65), is_init(false)
{
	themeFont = al_map_rgb(210,15,0); /* blood red */
	themeBackground = al_map_rgb(255,255,0); /* yellow */
	worldTileSet = std::make_tuple("Anikki_sq_10x10.bmp",10,10);
    //Vegtam added biomeTileSet in case we want it to be different in the future
    biomeTileSet = std::make_tuple("Anikki_sq_10x10.bmp",10,10);
    //Vegtam end
}

bool Model::init()
{
	player.init();
	world.buildBiomes(); /* generate terrain */
	is_init = true;
	return is_init;
}
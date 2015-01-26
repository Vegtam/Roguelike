#include <tuple>
#include <allegro5/allegro.h>

#include "Model.hpp"
Model::Model():world(65,65) //Vegtam - do I need to do this with biome?
{
	themeFont = al_map_rgb(210,15,0); /* blood red */
	themeBackground = al_map_rgb(255,255,0); /* yellow */
	worldTileSet = std::make_tuple("Anikki_sq_10x10.bmp",10,10);
    //Vegtam added biomeTileSet in case we want it to be different in the future
    biomeTileSet = std::make_tuple("Anikki_sq_10x10.bmp",10,10);
    //Vegtam end
	player.init();
}
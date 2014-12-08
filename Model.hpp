#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <allegro5/allegro.h> 
#include <string>
#include <tuple>
#include <stdint.h>
#include "World.hpp"
#include "Player.hpp"

class Model
{
private:
	ALLEGRO_COLOR themeBackground;
	ALLEGRO_COLOR themeFont;
	std::tuple<std::string, uint32_t, uint32_t> worldTileSet;
	World world;
	Player player;

public:
	Model();
	virtual ~Model(){};
	inline ALLEGRO_COLOR getThemeBackground(){return themeBackground;};
	inline ALLEGRO_COLOR getThemeFont(){return themeFont;};
	inline std::tuple<std::string, uint32_t, uint32_t> getWorldTileSet(){return worldTileSet;};
	inline World& getWorld(){return world;};
	inline Player& getPlayer(){return player;};
};

#endif
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
        //Vegtam added the biomeTileSet tuple variable
        std::tuple<std::string, uint32_t, uint32_t> biomeTileSet;
        //Vegtam end
	World world;
        
        
        
	Player player;
        //Vegtam codes...
        Biome biome;
        //maybe?
        

public:
	Model();
	virtual ~Model(){};
	inline ALLEGRO_COLOR getThemeBackground(){return themeBackground;};
	inline ALLEGRO_COLOR getThemeFont(){return themeFont;};
	inline std::tuple<std::string, uint32_t, uint32_t> getWorldTileSet(){return worldTileSet;};
        //Vegtam added getBiomeTileSet
        inline std::tuple<std::string, uint32_t, uint32_t> getBiomeTileSet(){return biomeTileSet;};
        //Vegtam end
	inline World& getWorld(){return world;};
        //Vegtam added a getBiome
        inline Biome& getBiome(){return world.worldMap[player.getWorldX()][player.getWorldY()];};
        //Vegtam end
	inline Player& getPlayer(){return player;};
};

#endif
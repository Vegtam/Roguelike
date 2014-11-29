#include <vector>
#include <iostream>
#include <fstream>

#include <allegro5/allegro.h> //for al_rest

#include "Allegro.hpp"
#include "Display.hpp"
#include "Displayable.hpp"
#include "ResourceSet.hpp"
#include "TileSet.hpp"
#include "TileMap.hpp"
#include "Tile.hpp"

int main(int argc, char **argv)
{
	Allegro alg;
	Display disp;
	ALLEGRO_COLOR bloodred;
	ALLEGRO_COLOR limegreen;
	ALLEGRO_EVENT_QUEUE* evq;
	ALLEGRO_EVENT ev;
	std::vector<Displayable*> to_draw;

	std::ifstream ifs ("USMap.txt");
	int tick = 1;

	if(alg.init() && 
	   disp.init() &&
	   (evq = al_create_event_queue()) != NULL)
	{
		al_register_event_source(evq, disp.getEventSource());

		ResourceSet<TileSet> fs ("../../tileset/");
		TileSet& ts = fs.get("Anikki_sq_10x10.bmp"); 

		ts.init(10,10);

		//std::cout<<"Tiles in set: "<<ts.numTiles()<<std::endl;
		bloodred = al_map_rgb(210,15,0);
		limegreen = al_map_rgb(153,255,0);

		std::vector<std::string> map;
		std::string line;
		uint32_t max_len;

		while(!ifs.eof())
		{
			getline(ifs,line);
			map.push_back(line);
			if(line.size()>max_len)
			{
				max_len = line.size();
			}
		}

		TileMap tmap;

		tmap.init(200,
			      200,
			      max_len*10,
			      map.size()*10,
			      max_len,
			      map.size(),
			      &ts);

		std::vector<Tile>* tile_array = tmap.getTiles();
		//std::cout <<"Num lines: "<<map.size()<<std::endl;
		//std::cout <<"Max Len: "<<max_len<<std::endl;

		uint32_t index = 0;
		for(auto& line: map)
		{
			bool empty_line = true;
			//std::cout<<line<<std::endl;
			for(auto& chr: line)
			{
				empty_line = false;
				(*tile_array)[index].setIndex((uint32_t)chr);
				(*tile_array)[index].setFore(bloodred);
				(*tile_array)[index].setBack(limegreen);
				index++;
			}
			//std::cout <<"line "<<index<<std::endl;
			while(index%max_len != 0 || empty_line)
			{
				empty_line=false;
				(*tile_array)[index].setIndex((uint32_t)' ');
				(*tile_array)[index].setFore(bloodred);
				(*tile_array)[index].setBack(limegreen);
				index++;
			}
			//std::cout <<"pad "<<index<<std::endl;
		}

		if(index != (max_len*map.size()))
		{
			std::cout<<"Wtf"<<index<<" "<<max_len<<" "<<map.size()<<std::endl;
			return -1;
		}

		tmap.render();
		to_draw.push_back(&tmap);

		while(1)
		{
			disp.clear(al_map_rgba_f(1,1,0,0));
			disp.render(to_draw);
			al_wait_for_event(evq, &ev);
			disp.handler(&ev);
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				break;
			}

		}		
		
		al_destroy_event_queue(evq);
	}
	return 0;
}
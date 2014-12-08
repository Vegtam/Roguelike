#include <vector>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <allegro5/allegro.h> //for al_rest

#include "Allegro.hpp"
#include "Display.hpp"
#include "ResourceSet.hpp"
#include "Font.hpp"
#include "TileSet.hpp"
#include "Image.hpp"

int main(int argc, char **argv)
{
	Allegro alg;
	Display disp;
	ALLEGRO_COLOR bloodred;
	ALLEGRO_COLOR limegreen;
	ALLEGRO_EVENT_QUEUE* evq;
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMER* tmr;  
	std::vector<Displayable*> to_draw;

	int tick = 1;

	if(alg.init() && 
	   disp.init() &&
	   (evq = al_create_event_queue()) != NULL)
	{
		tmr = al_create_timer(1); //once per second
		al_register_event_source(evq, disp.getEventSource());
		al_register_event_source(evq, al_get_timer_event_source(tmr));

		ResourceSet<Font> fs ("fonts/");
		Font& fnt = fs.get("Roboto-Bold.ttf"); 

		//std::cout<<"Tiles in set: "<<ts.numTiles()<<std::endl;
		bloodred = al_map_rgb(210,15,0);
		limegreen = al_map_rgb(153,255,0);

		std::vector <std::string> mytxt {"Domo arigato", 
		                       "Mr Roboto", 
		                       "Allons enfants de la Patrie", 
		                       "I wouldn't do that if I were you"};

		TextPane pane;
		TextPane pane2;
		TextPane pane3;

		pane.init(fnt.get(12), 200,200, 100,100);
		pane2.init(fnt.get(16), 300,300, 100,100);
		pane3.init(fnt.get(20), 400,400, 100,100);

		pane.write(mytxt[0]);
		pane2.write(mytxt[0]);
		pane3.write(mytxt[0]);
		pane.render();
		pane2.render();
		pane3.render();
		to_draw.push_back(&pane);
		to_draw.push_back(&pane2);
		to_draw.push_back(&pane3);

		uint32_t idx = 1;

		al_start_timer(tmr);

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
			else if( ev.type == ALLEGRO_EVENT_TIMER)
			{
				//std::cout<<"tick"<<std::endl;
				pane.write(mytxt[idx]);
				pane.render();
				pane2.write(mytxt[idx]);
				pane2.render();
				pane3.write(mytxt[idx]);
				pane3.render();
				
				idx = (idx+1)%mytxt.size();
			}

		}		
		
		al_destroy_event_queue(evq);
	}
	return 0;
}
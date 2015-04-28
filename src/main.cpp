//so I don't forget... Look into Djikstra Algorithm for pathfinding.. Roads as well maybe?
#include <iostream>
#include <map>
#include <tuple>
#include <allegro5/allegro.h> 

#include "Allegro.hpp"
#include "Display.hpp"

#include "ResourceSet.hpp"
#include "View.hpp"

#include "Font.hpp"
#include "Image.hpp"
#include "Model.hpp"

#include "TitleView.hpp"
#include "CreditsView.hpp"
#include "WorldView.hpp"
#include "BiomeView.hpp"
#include "CharacterCreationNameView.hpp"

#define FPS 60

int main(int argc, char **argv)
{
	Allegro alg;
	Display disp;
	ALLEGRO_EVENT_QUEUE* evq;
	ALLEGRO_EVENT ev;
	//ALLEGRO_TIMER* tmr;
	bool redraw = true;
	std::map<DefinedViews, std::tuple<View*,bool>> viewMap;
	
	DefinedViews currentView = DefinedViews::TITLE_VIEW;

	
	
	if(alg.init() && 
	   disp.init() &&
	   (evq = al_create_event_queue()) != NULL)
	{
		//tmr = al_create_timer((float)1/FPS);
		al_register_event_source(evq, disp.getEventSource());
		//al_register_event_source(evq, al_get_timer_event_source(tmr));
		al_register_event_source(evq, al_get_keyboard_event_source());

		Model model;

		ResourceSet<Font> fs ("../fonts/");
		ResourceSet<TileSet> ts ("../tileset/");
		ResourceSet<Image> is ("../image/");

		/* @todo could check return values of init calls */
		TitleView titleview(&model, &is);
		titleview.init();

		CreditsView creditView(&model, &fs);		
		WorldView worldview(&model, &fs,&ts);		        
        BiomeView biomeView(&model, &fs, &ts);
		CharacterCreationNameView characterCreationNameView(&model, &fs);

		viewMap[DefinedViews::TITLE_VIEW] = std::make_tuple(&titleview, true);
		viewMap[DefinedViews::CREDITS_VIEW] = std::make_tuple(&creditView,false);
		viewMap[DefinedViews::WORLD_VIEW] = std::make_tuple(&worldview,false);
        viewMap[DefinedViews::BIOME_VIEW] = std::make_tuple(&biomeView,false);
		viewMap[DefinedViews::CHARACTER_CREATION_NAME_VIEW] = std::make_tuple(&characterCreationNameView,false);

		while(1)
		{
			if (redraw && al_is_event_queue_empty(evq))
			{
				disp.clear(model.getThemeBackground());
				disp.render(std::get<0>(viewMap[currentView])->draw());
			}
			al_wait_for_event(evq, &ev);
			
			currentView = std::get<0>(viewMap[currentView])->handleEvent(&ev);
			disp.handler(&ev);
			redraw = true;
		

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || 
				currentView == DefinedViews::QUIT_VIEW)
			{
				break;
			}
			if(not std::get<1>(viewMap[currentView]))
			{
				std::get<1>(viewMap[currentView])=std::get<0>(viewMap[currentView])->init();
			}
		}
		al_destroy_event_queue(evq);
	}
	return 0;
}

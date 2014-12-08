
#include <iostream>
#include <map>
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

#define FPS 60

int main(int argc, char **argv)
{
	Allegro alg;
	Display disp;
	ALLEGRO_EVENT_QUEUE* evq;
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMER* tmr;
	std::map<DefinedViews, View*> viewMap;
	Model model;

	DefinedViews currentView = DefinedViews::TITLE_VIEW;

	
	
	if(alg.init() && 
	   disp.init() &&
	   (evq = al_create_event_queue()) != NULL)
	{
		tmr = al_create_timer((float)1/FPS);
		al_register_event_source(evq, disp.getEventSource());
		al_register_event_source(evq, al_get_timer_event_source(tmr));
		al_register_event_source(evq, al_get_keyboard_event_source());

		ResourceSet<Font> fs ("../../fonts/");
		ResourceSet<TileSet> ts ("../../tileset/");
		ResourceSet<Image> is ("../../image/");

		TitleView titleview(&model, &is);
		titleview.init();

		CreditsView creditView(&model, &fs);
		creditView.init();

		viewMap[DefinedViews::TITLE_VIEW] = &titleview;
		viewMap[DefinedViews::CREDITS_VIEW] = &creditView;

		al_start_timer(tmr);

		while(1)
		{
			disp.clear(al_map_rgba_f(1,1,0,0));
			disp.render(viewMap[currentView]->draw());
			al_wait_for_event(evq, &ev);
			
			/* call event handlers */
			currentView = viewMap[currentView]->handleEvent(&ev);
			disp.handler(&ev);

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || 
				currentView == DefinedViews::QUIT_VIEW)
			{
				break;
			}
			
		}
		al_destroy_event_queue(evq);
	}
	return 0;
}
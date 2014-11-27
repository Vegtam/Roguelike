#include <vector>
#include <allegro5/allegro.h> //for al_rest

#include "Allegro.hpp"
#include "Display.hpp"
#include "Displayable.hpp"
#include "FontSet.hpp"
#include "Font.hpp"
#include "Text.hpp"

int main(int argc, char **argv)
{
	Allegro alg;
	Display disp;
	ALLEGRO_COLOR bloodred;
	ALLEGRO_EVENT_QUEUE* evq;
	ALLEGRO_EVENT ev;
	std::vector<Displayable*> to_draw;
	int tick = 1;

	if(alg.init() && 
	   disp.init() &&
	   (evq = al_create_event_queue()) != NULL)
	{
		al_register_event_source(evq, disp.getEventSource());

		FontSet fs("../../fonts/");
		bloodred = al_map_rgb(210,15,0);

		Text title (fs.getFont("Roboto-Black.ttf"), 
			        bloodred,
			        "Dead On Survival");
		title.setPos(25,345);
		title.setSize(30);
		to_draw.push_back(&title);

		Text subtitle (fs.getFont("Roboto-MediumItalic.ttf"),
			           bloodred,
			           "the rottening");
		subtitle.setPos(40,385);
		subtitle.setSize(25);
		
		to_draw.push_back(&subtitle);

		while(1)
		{
			disp.clear(al_map_rgb_f(1,1,0));
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
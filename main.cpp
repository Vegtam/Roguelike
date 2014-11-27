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
	std::vector<Displayable*> to_draw;

	if(alg.init() && disp.init())
	{
		FontSet fs("fonts/");
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

		disp.clear(al_map_rgb_f(1,1,0));
		disp.render(to_draw);
		al_rest(5.0);

	}
	return 0;
}
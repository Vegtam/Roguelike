#include <vector>
#include <string>
#include <allegro5/allegro.h>

#include "CreditsView.hpp"
#include "Displayable.hpp"

bool CreditsView::init()
{
	int result = false; 
	if( model && fontset) 
	{
		credits.init(fontset->get("Roboto-Bold.ttf").get(50), 380,150,450,450);
		credits.setFore(al_map_rgb(210,15,0)); /*blood red*/
		credits.setBack(al_map_rgba_f(1,1,0,0));/*yellow*/
		credits.write("Creator:");
		credits.write("    Vegtam");
		credits.write(" ");
		credits.write("Developers:");
		credits.write("    Vegtam");
		credits.write("    cupguy47829");
		
		credits.render();

		drawList.push_back(&credits);
		result = is_init = true;
	} 
	return result;
}

DefinedViews CreditsView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::CREDITS_VIEW;
	switch(ev->keyboard.keycode)
	{
		case ALLEGRO_KEY_ESCAPE: /* return to tile Game*/
			dv = DefinedViews::TITLE_VIEW; 
			break;
		default:
			break; 
	}
	return dv;
}

DefinedViews CreditsView::handleEvent(ALLEGRO_EVENT* ev)
{
	/* for now just handle start and quit */
	DefinedViews dv = DefinedViews::CREDITS_VIEW;

	if( ev )
	{
		switch (ev->type)
		{
			case ALLEGRO_EVENT_KEY_CHAR:
				dv = handleKeyPress(ev);
				break;
			default:
				break;
		}
	}
	return dv;
}

std::vector<Displayable*>& CreditsView::draw()
{
	return drawList;
}

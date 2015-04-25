#include <vector>
#include <string>
#include <allegro5/allegro.h>

#include "Image.hpp"
#include "TitleView.hpp"
#include "World.hpp"

bool TitleView::init()
{
	int result = false; 
	if( model && imageset) 
	{
		Image& title = imageset->get(titlescreen);
		title.init(0, 0, 1024, 768); /* probably need a better way of specifying this*/
		drawList.push_back(&title);
		result = is_init = true;
	} 
	return result;
}

DefinedViews TitleView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::TITLE_VIEW;
	switch(ev->keyboard.keycode)
	{
		case ALLEGRO_KEY_N: /* New Game*/
			dv = DefinedViews::CHARACTER_CREATION_NAME_VIEW;
			model->init();
			break;
		case ALLEGRO_KEY_R: /* Credits */
			dv = DefinedViews::CREDITS_VIEW;
			break;
		case ALLEGRO_KEY_C: /* Continue */
			if (model->isInit())
			{
				dv = DefinedViews::WORLD_VIEW;
			}
			break;
		case ALLEGRO_KEY_S: /* Settings */
			/* not supported yet */
			break;
		case ALLEGRO_KEY_Q: /* Quit */
			dv = DefinedViews::QUIT_VIEW;
			break;
		default:
			break; 
	}
	return dv;
}

DefinedViews TitleView::handleEvent(ALLEGRO_EVENT* ev)
{
	/* for now just handle start and quit */
	DefinedViews dv = DefinedViews::TITLE_VIEW;

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

std::vector<Displayable*>& TitleView::draw()
{
	return drawList;
}
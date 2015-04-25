#include <vector>
#include <string>
#include <iostream>
#include <allegro5/allegro.h>

#include "CharacterCreationNameView.hpp"
#include "View.hpp"
#include "Font.hpp"
#include "ResourceSet.hpp"
#include "Model.hpp"

bool CharacterCreationNameView::init()
{
	int result = false;
	if( model && fontset)
	{
		Font& fnt = fontset->get("Roboto-Bold.ttf");
		ALLEGRO_FONT* f = fnt.get(12);
		ALLEGRO_FONT* f2 = fnt.get(20);
		if( f && 
			title.init(f2,
					   400,
					   10,
					   al_get_text_width(f2, "Character Creation"),
					   al_get_font_line_height(f2)) &&
			nameLabel.init(f,
		                   50,
			               50,
			               al_get_text_width(f,"Name: "),
			               al_get_font_line_height (f)) )
		{
			nameLabel.setFore(model->getThemeFont());
			nameLabel.setBack(model->getThemeBackground());
			nameLabel.write("Name: ");
			title.setFore(model->getThemeFont());
			title.setBack(model->getThemeBackground());
			title.write("Character Creation");
			if(name.init(f, 
				         nameLabel.getX()+nameLabel.getWidth()+4,
				         nameLabel.getY(),
				         al_get_font_line_height (f)*15) )
			{
				name.setInFocus(true);
				name.setFore(model->getThemeFont());
				name.setBack(model->getThemeBackground());

				nameLabel.render();
				name.render();
				title.render();

				drawList.push_back(&nameLabel);
				drawList.push_back(&name);
				drawList.push_back(&title);
				result = true;
			}
		}
	}
	return result;
}

DefinedViews CharacterCreationNameView::handleKeyPress(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::CHARACTER_CREATION_NAME_VIEW;
	switch(ev->keyboard.keycode)
	{
		case ALLEGRO_KEY_ENTER: /* for debug, remove later */
			std::cout<<name.getCurrent()<<std::endl;
			break;
		case ALLEGRO_KEY_TAB: /* for debug, remove later */
			name.setInFocus(!name.getInFocus()); 
			break;
		case ALLEGRO_KEY_N: /* for debug, remove later */
			if(!name.getInFocus())
			{
				dv = DefinedViews::WORLD_VIEW;
				/* should really be setting the name in the model at the point where
				   we switch from character creation to new game before we clear out 
				   the name*/
				name.clear();
				name.render();
				break;
			}
			/* fall through to handle event */
		default:
			name.handleEvent(ev);
			name.render();
			break;
	}
	return dv;
}

DefinedViews CharacterCreationNameView::handleEvent(ALLEGRO_EVENT* ev)
{
	DefinedViews dv = DefinedViews::CHARACTER_CREATION_NAME_VIEW;
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

std::vector<Displayable*>& CharacterCreationNameView::draw()
{
	return drawList;
}
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <stdint.h>
#include <iostream>

#include "TextEntry.hpp"
#include "TextPane.hpp"

bool TextEntry::init(ALLEGRO_FONT* fnt, uint32_t x, uint32_t y, uint32_t w)
{
	bool result = false;
	if(fnt)
	{
		result = TextPane::init(fnt, x, y, w, al_get_font_line_height (fnt));
		if (result)
		{
			std::string tmp = "_";
			while(al_get_text_width(fnt, tmp.c_str()) <= w)
			{
				tmp += "_";
			}
			maxChars = tmp.size()-2; // -1 to get back in the pane, 
			                         // -1 again to allow for the cursor
		}
	}
	return result;
}

void TextEntry::handleEvent(ALLEGRO_EVENT* ev)
{
	if( ev && inFocus )
	{
		switch (ev->type)
		{
			case ALLEGRO_EVENT_KEY_CHAR:
				handleKeyPress(ev);
				break;
			default:
				break;
		}
	}
}

void TextEntry::handleKeyPress(ALLEGRO_EVENT* ev)
{
	bool change = false;
	

	switch(ev->keyboard.keycode)
	{
		case ALLEGRO_KEY_LEFT:
			cursorPos = (cursorPos-1) < 0 ? cursorPos : cursorPos-1;
			change = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			cursorPos = (cursorPos+1) > current.size() ? cursorPos : cursorPos+1;
			change = true;
			break;
		case ALLEGRO_KEY_DELETE:
			/* if there are characters and the cursor is not at the end */
			if(current.size() && cursorPos < current.size())
			{
				current.erase(current.begin()+cursorPos);
				change = true;
			}
			break;
		case ALLEGRO_KEY_BACKSPACE:
			if(current.size() && cursorPos > 0)
			{
				current.erase(current.begin()+cursorPos-1);
				cursorPos = (cursorPos-1) < 0 ? cursorPos : cursorPos-1;
				change = true;
			}
			break;
		case ALLEGRO_KEY_ENTER:
			break;
		default:
			char key = 0;
			if( al_utf8_width(ev->keyboard.unichar) == 1 && 
			    al_utf8_encode(&key, ev->keyboard.unichar) &&
			    (key>=32 && key<=127))
			{
				/* only add this character if we have space */
				if(current.size() < maxChars )
				{
					current.insert(current.begin()+cursorPos, key);
					cursorPos++;
					change = true;
				}
			}
			break;
	}
	
	if(change)
	{
		char curr[current.size()+2];
		int idx = 0;
		for (auto i : current)
		{
			if( idx == cursorPos)
			{
				curr[idx]='|';
				idx++;
			}
			curr[idx] = i;
			idx++;
		}
		if( idx == cursorPos)
		{
			curr[idx]='|';
		}
		curr[current.size()+1] = 0;
		write(std::string(curr));
	}
}

void TextEntry::clear()
{
	if (isInit())
	{
		cursorPos = 0;
		current.clear();
		write("");
		inFocus = true;
	}
}

void TextEntry::draw()
{
	if( isInit() )
	{
		const ALLEGRO_TRANSFORM * t = al_get_current_transform();
		float width = inFocus?2:1;
		float x1 = (float)(getX()-width);
		float y1 = (float)(getY()-width);
		float x2 = (float)(getX()+getWidth()+width);
		float y2 = (float)(getY()+getHeight()+width);
		al_transform_coordinates(t, &x1, &y1);
		al_transform_coordinates(t, &x2, &y2);
		al_draw_rectangle(x1, y1, 
			              x2, y2,
						  getFore(),
						  width);
		TextPane::draw();
	}

}
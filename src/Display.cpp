#include <allegro5/allegro.h>

#include <stdint.h>
#include <vector>
#include <iostream>

#include "Display.hpp"

Display::Display():width(kDefaultWidth),height(kDefaultHeight),
	is_init(false),display(NULL)
{
}

Display::Display(uint32_t w, uint32_t h):width(w),height(h), 
	is_init(false),display(NULL)
{
	/* exceptions are lame so don't do complicated things in constructors */
}

bool Display::init()
{
	al_set_new_display_flags(ALLEGRO_RESIZABLE);

	ALLEGRO_MONITOR_INFO info;
	if(al_get_monitor_info(0,&info))
	{
		uint32_t m_w = info.x2-info.x1;
		uint32_t m_h = info.y2-info.y1;
		if (width != m_w && (m_w/100)*100 < width)
		{
			width = (m_w/100)*100; 
		}
		if( (m_h/100)*100 < height)
		{
			height = (m_h/100)*100;
		}
		
	}

	display = al_create_display(width,height);
	
	is_init = (display != NULL);
	return is_init;
}

void Display::cleanup()
{
	if( is_init )
	{
		al_destroy_display(display);
		is_init = false;
	}
}

Display::~Display()
{
	cleanup();	
}

void Display::clear(ALLEGRO_COLOR color)
{
	if(is_init)
	{
		setCurrent();
		al_clear_to_color(color);
	}
}

void Display::render (std::vector<Displayable*>& to_draw)
{
	if(is_init)
	{
		ALLEGRO_TRANSFORM t;
		al_identity_transform(&t);
		al_scale_transform(&t, (float)width/(float)kDefaultWidth,  (float)height/(float)kDefaultHeight);
		setCurrent();
		al_use_transform(&t);
		al_hold_bitmap_drawing(true);
		for(std::vector<Displayable*>::iterator it = to_draw.begin();
			it != to_draw.end(); it++)
		{
			/* Draw the item and scale it based on the current display size */
			(*it)->draw();
		}
		al_hold_bitmap_drawing(false);
		al_flip_display();

		/* reset the transform until then next time*/
		al_identity_transform(&t);
		al_use_transform(&t);
	}
}

ALLEGRO_EVENT_SOURCE* Display::getEventSource()
{
	if(is_init)
	{
		return al_get_display_event_source(display);
	}
	return NULL;
}

void Display::resize(uint32_t w, uint32_t h)
{
	al_resize_display(display, w, h);
}

void Display::handler(ALLEGRO_EVENT* ev)
{
	if (is_init && ev)
	{
		switch (ev->type)
		{
			case ALLEGRO_EVENT_DISPLAY_RESIZE:
				if(ev->display.source == display)
				{
					width = ev->display.width;
					height = ev->display.height;
					al_acknowledge_resize(display);
				}
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				if( ev->display.source == display)
				{
					cleanup();
				}
				break;
			default:
				break;
		}
	}
}

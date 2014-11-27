#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <stdint.h>
#include <allegro5/allegro.h>
#include <vector>
#include <memory>
#include "Displayable.hpp"


class Display
{
private:
	const uint32_t kDefaultWidth = 1024;
	const uint32_t kDefaultHeight = 768;
	uint32_t width;
	uint32_t height;
	bool is_init;
	ALLEGRO_DISPLAY* display;
	inline void setCurrent() { if(is_init) al_set_target_backbuffer(display);}
public:
	Display();
	Display(uint32_t w, uint32_t h);
	bool init();
	void cleanup();
	inline bool checkInit() {return is_init;};
	virtual ~Display();
	void clear(ALLEGRO_COLOR);
	void render (std::vector<Displayable*>&);
	void handler(ALLEGRO_EVENT*);
	void resize(uint32_t w, uint32_t h);
	ALLEGRO_EVENT_SOURCE* getEventSource();
};

#endif
#ifndef ALLEGRO_HPP_
#define ALLEGRO_HPP_
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class Allegro
{
private:
	bool is_init;
public:
	Allegro():is_init(false){};
	bool init();
	inline bool checkInit() {return is_init;};
	virtual ~Allegro();
};
#endif

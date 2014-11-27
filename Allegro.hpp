#ifndef ALLEGRO_HPP_
#define ALLEGRO_HPP_

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
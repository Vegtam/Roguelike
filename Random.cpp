#include <cstdlib>
#include <ctime>

#include "Random.hpp"

Random* Random::rnd = NULL;
bool Random::init = false;

Random::Random()
{
	srand(time(NULL));
	init = true;
}

Random* Random::get()
{
	if(!init)
	{
		rnd = new Random();
	}
	return rnd;
}

int Random::randInt()
{
	return rand();
}

float Random::randFloat(float max)
{
	int r = randInt();
    float s = (float)(r & 0x7fff)/(float)0x7fff;

    return (s * max);
}


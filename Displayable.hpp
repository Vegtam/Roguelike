#ifndef DISPLAYBLE_HPP_
#define DISPLAYBLE_HPP_

class Displayable
{
public:
	virtual void draw(float xscale, float yscale) = 0;
};

#endif
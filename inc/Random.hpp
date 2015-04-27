#ifndef RANDOM_HPP
#define RANDOM_HPP

class Random
{
private:
	static Random* rnd;
	static bool init;
	Random();
public:
	static Random* get();
	int randInt();
	float randFloat(float max);
};
#endif
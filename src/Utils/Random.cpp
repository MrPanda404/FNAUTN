#include "Random.h"

std::mt19937 Random::rng;

void Random::Init()
{
	std::random_device rd;
	rng.seed(rd());
}

int Random::GetInt(int min, int max)
{
	std::uniform_int_distribution<int> distrib(min, max);
	return distrib(rng);
}

float Random::GetFloat(float min, float max)
{
	std::uniform_real_distribution<float> distrib(min, max);
	return distrib(rng);
}

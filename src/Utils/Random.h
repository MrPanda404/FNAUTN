#pragma once
#include <random>

class Random
{
public:
	static void Init();
	static int GetInt(int min, int max);
	static float GetFloat(float min, float max);

private:
	static std::mt19937 rng;
};


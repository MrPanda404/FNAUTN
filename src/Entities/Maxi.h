#pragma once
#include "RandomMovingEnemy.h"

class Maxi : public RandomMovingEnemy
{
public:
	Maxi() = default;
	Maxi(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
};


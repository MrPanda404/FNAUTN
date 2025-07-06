#pragma once
#include "RandomMovingEnemy.h"

class Vastag : public RandomMovingEnemy
{
public:
	Vastag() = default;
	Vastag(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
};


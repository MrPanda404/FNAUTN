#pragma once
#include "Enemy.h"

class Vastag : public Enemy
{
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
};


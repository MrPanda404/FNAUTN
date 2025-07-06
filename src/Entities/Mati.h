#pragma once
#include "Enemy.h"

class Mati : public Enemy
{
public:
	Mati() = default;
	Mati(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
	void Move() override;
};


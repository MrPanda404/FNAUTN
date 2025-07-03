#pragma once
#include "Enemy.h"

class Kloster : public Enemy
{
public:
	Kloster() = default;
	Kloster(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
};


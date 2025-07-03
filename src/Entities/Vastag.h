#pragma once
#include "Enemy.h"

class Vastag : public Enemy
{
public:
	Vastag() = default;
	Vastag(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;
private:
	std::array<int, 4> roomsFilter;
	std::array<sf::Vector2i, 6> spotsFilter;
};


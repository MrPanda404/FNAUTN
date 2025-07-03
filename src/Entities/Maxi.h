#pragma once
#include "Enemy.h"

class Maxi : public Enemy
{
public:
	Maxi() = default;
	Maxi(const float& dt);
	// Inherited via Enemy
	void Start() override;
	void Update() override;
	void Stop() override;

	void Move();
private:
	std::array<int, 3> roomsFilter;
	std::array<sf::Vector2i, 3> spotsFilter;
};


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
	std::vector<int> roomsFilter;
	std::vector<sf::Vector2i> spotsFilter;
};


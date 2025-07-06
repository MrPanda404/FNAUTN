#pragma once
#include "Enemy.h"
class RandomMovingEnemy : public Enemy
{
public:
	virtual void Move();
protected:
	std::vector<int> roomsFilter;
	std::vector<sf::Vector2i> spotsFilter;
};


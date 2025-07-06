#pragma once
#include "Enemy.h"

void Enemy::Move()
{
}

bool Enemy::Timer()
{
	timer += *deltaTime;
	if (timer > moveInterval) {
		std::cout << "timer: " << timer;
		timer = 0;
		return true;
	}
	return false;
}

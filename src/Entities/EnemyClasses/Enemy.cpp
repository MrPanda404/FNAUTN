#pragma once
#include "Enemy.h"

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

std::pair<int, const sf::Vector2i*> Enemy::GetPosAndID()
{
	return { ID, &currentPos };
}

void Enemy::SetPosition(sf::Vector2i pos)
{
	Room::SetOccupied(currentPos.x, currentPos.y, false);
	currentPos = pos;
	Room::SetOccupied(currentPos.x, currentPos.y, true);
}

std::pair<int, const bool*> Enemy::GetMovedAndID()
{
	return { ID, &moved };
}

std::pair<int, const int*> Enemy::GetLastRoomAndID()
{
	return { ID, &lastRoom };
}

void Enemy::ResetMoved()
{
	moved = false;
}

#include "RandomMovingEnemy.h"

void RandomMovingEnemy::Move()
{
	int randValue = Random::GetInt(1, 20);
	std::cout <<name<< " " << randValue << std::endl;
	if (randValue > currentDifficulty) {
		return;
	}

	int newRoom;
	int newSpot;

	if (Random::GetInt(1, 2) == 1) {
		std::cout << "Same room" << std::endl;
		newRoom = currentPos.x;
	}
	else {
		std::cout << "New Room" << std::endl;
		newRoom = Room::GetValidRandomAdyacent(currentPos.x, roomsFilter);
	}

	newSpot = Room::GetValidRandomSpot(newRoom, currentPos, spotsFilter);

	if (Room::CheckOccupied(newRoom, newSpot)) {
		std::cout << "Room: " << currentPos.x << " - Spot: " << currentPos.y << std::endl;
		std::cout << "It's occupied :v" << std::endl;
		return;
	}

	lastRoom = currentPos.x;
	SetPosition({ newRoom, newSpot });
	moved = true;

	std::cout<<name << " Room: " << currentPos.x << " - Spot: " << currentPos.y << std::endl;
}

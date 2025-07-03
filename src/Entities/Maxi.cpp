#include "Maxi.h"

Maxi::Maxi(const float& dt)
	:roomsFilter({ 0 })
{
	deltaTime = &dt;
	std::cout << "dt: " << deltaTime << std::endl;
}

void Maxi::Start()
{
	{
		name = "Maxi";
		ID = 2;
		SetPosition({ 4,1 });

		roomsFilter = { 2, 6, 7 };
		spotsFilter = { sf::Vector2i{ 4,4 } ,{ 0,5 }, { 0,7 } };

		sequence = {
			{7, 3},
			{7, 1},
			{0, 6}
		};

		difficulty = { 0, 3, 0, 2, 5, 10 };

		currentDifficulty = difficulty.at(5);

		moveInterval = 3.15f;
	}
}

void Maxi::Update()
{
	timer += *deltaTime;
	if (timer > moveInterval) {
		Move();
		timer = 0;
	}
}

void Maxi::Stop()
{
}

void Maxi::Move()
{
	int randValue = Random::GetInt(1, 20);
	std::cout << randValue << std::endl;
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
		newRoom = Room::GetRandomAdyacent(currentPos.x);
	}

	newSpot = Random::GetInt(1, Room::GetSpots(newRoom));

	if (Room::CheckOccupied(newRoom, newSpot)) {
		std::cout << "Room: " << currentPos.x << " - Spot: " << currentPos.y << std::endl;
		std::cout << "It's occupied :v" << std::endl;
		return;
	}
	
	lastRoom = currentPos.x;
	SetPosition({newRoom, newSpot});
	moved = true;

	std::cout << "Room: " << currentPos.x << " - Spot: " << currentPos.y << std::endl;
}

#include "Maxi.h"

Maxi::Maxi(const float& dt)
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

		moveInterval = 4.7f;
	}
}

void Maxi::Update()
{
	if (Timer()) {
		std::cout << " Maxi" << std::endl;
		Move();
	}
}

void Maxi::Stop()
{
}
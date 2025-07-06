#include "Vastag.h"

Vastag::Vastag(const float& dt)
{
	deltaTime = &dt;
}

void Vastag::Start()
{
	{
		name = "Vastag";
		ID = 3;
		SetPosition({ 6,2 });

		roomsFilter = { 3, 4, 5, 7 };
		spotsFilter = {sf::Vector2i { 1, 4 }, { 1, 3 }, { 1, 2 }, { 1, 1 }, { 0, 7 }, { 0, 6 } };

		sequence = {
			{0,5},
			{8,3},
			{7,4}
		};

		difficulty = { 0, 1, 5, 4, 7, 12 };

		currentDifficulty = difficulty.at(5);

		moveInterval = 4.8f;
	}
}

void Vastag::Update()
{
	if (Timer()) {
		std::cout << " Vastag" << std::endl;
		Move();
	}
	
}

void Vastag::Stop()
{
}

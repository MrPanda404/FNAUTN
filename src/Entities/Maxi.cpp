#include "Maxi.h"

void Maxi::Start()
{
	{
		name = "Maxi";
		ID = 2;
		currentPos = { 4, 1 };

		sequence = {
			{7, 3},
			{7, 1},
			{0, 6}
		};

		difficulty = { 0, 3, 0, 2, 5, 10 };
	}
}

void Maxi::Update()
{
}

void Maxi::Stop()
{
}

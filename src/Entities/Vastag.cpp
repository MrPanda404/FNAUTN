#include "Vastag.h"

void Vastag::Start()
{
	{
		name = "Vastag";
		ID = 3;
		currentPos = { 6, 2 };

		sequence = {
			{0,5},
			{8,3},
			{7,4}
		};

		difficulty = { 0, 1, 5, 4, 7, 12 };
	}
}

void Vastag::Update()
{
}

void Vastag::Stop()
{
}

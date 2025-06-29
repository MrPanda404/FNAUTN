#include "Mati.h"

void Mati::Start()
{
	{
		name = "Mati";
		ID = 1;
		currentPos = { 9, 1 };

		sequence = {
			{8, 2 },
			{8, 1 },
			{9, 3 },
			{9, 2 },
			{9, 1}
		};

		difficulty = { 0, 1, 2, 6, 5, 16 };
	}
}

void Mati::Update()
{
}

void Mati::Stop()
{
}

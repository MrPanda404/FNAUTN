#include "Mati.h"

Mati::Mati(const float& dt)
{
	deltaTime = &dt;
}

void Mati::Start()
{
	{
		name = "Mati";
		ID = 1;
		SetPosition({ 9,1 });

		sequence = {
			{8, 2 },
			{8, 1 },
			{9, 3 },
			{9, 2 },
			{9, 1}
		};

		difficulty = { 0, 1, 2, 6, 5, 16 };

		moveInterval = 4.9f;
	}
}

void Mati::Update()
{
}

void Mati::Stop()
{
}

void Mati::Move()
{
}

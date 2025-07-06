#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Room.h"
#include "Random.h"
#include <iostream>

class Enemy
{
public:
	Enemy() = default;
	~Enemy() = default;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;
	virtual void Move();

	virtual bool Timer();


	std::pair<int, const sf::Vector2i*> GetPosAndID() { return { ID, &currentPos }; }

	void SetPosition(sf::Vector2i pos) { 
		Room::SetOccupied(currentPos.x, currentPos.y, false);
		currentPos = pos; 
		Room::SetOccupied(currentPos.x, currentPos.y, true);
	}

	std::pair<int, const bool*> GetMovedAndID() { return { ID, &moved }; }
	std::pair<int, const int*> GetLastRoomAndID() { return { ID, &lastRoom }; }

	void ResetMoved() { moved = false; }

protected:
	std::string name = "";
	int ID = 0;

	sf::Vector2i currentPos = {0,1};
	int lastRoom = 0;

	std::vector<int> difficulty = {};
	int currentDifficulty = 0;

	bool attackMode = false;
	bool reachedOffice = false;///discard at least one
	bool enteredOffice = false;
	bool moved = false;

	std::vector<sf::Vector2i> sequence = {};

	const float* deltaTime = nullptr;
	float timer = 0.f;
	float moveInterval = 0.f;
};


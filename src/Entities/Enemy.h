#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Room.h"

class Enemy
{
public:
	virtual ~Enemy() = default;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;

	std::pair<int, const sf::Vector2i*> GetPosAndID() { return { ID, &currentPos }; }

	void setPosition(sf::Vector2i pos) { 
		Room::SetOccupied(currentPos.x, currentPos.y, false);
		currentPos = pos; 
		Room::SetOccupied(currentPos.x, currentPos.y, true);
	}

protected:
	std::string name;
	int ID;

	sf::Vector2i currentPos = {0,1};
	int lastRoom;

	std::vector<int> difficulty;
	float opportunityRate;

	bool attackMode;
	bool reachedOffice;
	bool enteredOffice;

	std::vector<sf::Vector2i> sequence;
};


#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>

class Enemy
{
public:
	virtual ~Enemy() = default;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Stop() = 0;
protected:
	std::string name;
	int ID;

	sf::Vector2i currentPos;
	int lastRoom;

	int difficulty;
	float opportunityRate;

	bool attackMode;
	bool reachedOffice;
	bool enteredOffice;

	std::vector<sf::Vector2i> sequence;
};


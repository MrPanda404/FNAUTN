#pragma once
#include <string>

class Player
{
public:
	Player();
	std::string SwitchState();
private:
	bool isLookingAtCams;
};


#include "Player.h"

Player::Player()
	: isLookingAtCams(false)
{
}

std::string Player::SwitchState()
{
	isLookingAtCams = !isLookingAtCams;

	if (isLookingAtCams) {
		return "camera";
	}
	else return "office";
}

#pragma once
#include "Game.h"

class NightState : public State
{
public:
	void Start() override;
	void HandleInput() override;
	void Update() override;
	void Render() override;
	void Stop() override;

private:



};


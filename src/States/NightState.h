#pragma once
#include "State.h"
#include "GameFwd.h"
#include "Office.h"
#include "Camera.h"
#include "Player.h"
#include "NightViewManager.h"

class NightState : public State
{
public:
	NightState(GameDataRef data);

	void Start() override;
	void HandleInput() override;
	void Update() override;
	void Render() override;
	void Stop() override;

private:
	GameDataRef data;
	sf::Vector2f mousePos;
	Office office;
	Camera camera;
	Player player;
	NightViewManager NightManager;
};


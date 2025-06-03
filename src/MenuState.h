#pragma once
#include "State.h"
#include "Game.h"

class MenuState : public State
{
private:
	GameDataRef data;
	std::unordered_map<std::string, sf::Texture> textures;
	std::unordered_map<std::string, sf::Sprite> sprites;
	std::vector<std::string> drawOrder;
	std::unordered_map<std::string, sf::RectangleShape> buttons;

public:
	MenuState(GameDataRef data);

	virtual void Start();
	virtual void HandleInput();
	virtual void Update();
	virtual void Render();
	virtual void Stop();
	void SetupSprites();
	void SetupButtons();

};


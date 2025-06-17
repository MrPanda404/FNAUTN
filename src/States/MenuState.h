#pragma once
#include "State.h"
#include "Game.h"


enum MenuView {
	Menu,
	Settings,
	Credits
};

class MenuState : public State
{
public:
	MenuState(GameDataRef data);

	void Start() override;
	void HandleInput() override;
	void Update() override;
	void Render() override;
	void Stop() override;
	void SetupSprites();
	void SetupButtons();

private:
	GameDataRef data;

	std::unordered_map<std::string, sf::Texture> textures;
	sf::Texture creditsTex;
	sf::Texture settingTex;

	std::unordered_map<std::string, sf::Sprite> bgSprites;
	std::unordered_map<std::string, sf::Sprite> menuSprites;
	sf::Sprite settingsSprite;
	sf::Sprite creditsSprite;

	std::vector<std::string> drawOrder;
	std::vector<std::string> drawOrderBG;

	std::vector<Button> menuButtons;
	std::vector<Button> settingsButtons;
	Button backButton;

	sf::Vector2f mousePos;

	bool mouseMoved = false;

	MenuView menuView = Menu;
};


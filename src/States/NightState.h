#pragma once
#include "State.h"
#include "Game.h"

enum LeftDoor {

};
enum RightDoor {

};
enum Scroll {
	Left,
	Center,
	Right
};

class NightState : public State
{
public:
	NightState(GameDataRef data);

	void Start() override;
	void HandleInput() override;
	void Update() override;
	void Render() override;
	void Stop() override;

	void SetupSprites();
	void SetupButtons();
	void SetupShaders();
	void HorizontalScroll();

private:
	GameDataRef data;

	sf::Shader officeShader;

	std::unordered_map<std::string, sf::Texture> officeTextures;

	std::vector<sf::Sprite> officeSprites;


	std::vector<std::string> drawOrder;

	sf::Shader perspectiveShader;
	sf::Shader gammaShader;

	std::vector<Button> officeButtons;
	std::vector<Button> cameraButtons;

	sf::Vector2f mousePos;

	sf::RenderTexture renderTexture;

	Scroll scroll;
	float scrollOffset;

	std::vector<Button> test;

};


#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "ShaderManager.h"

enum Scroll {
	Left,
	Center,
	Right
};

class Office
{
public:

	Office(GameDataRef data, const sf::Vector2f& mousePos);

	void Setup();
	void Update();
	void Render();
	void CheckButtons();
	void CheckScroll();
	void HorizontalScroll();
	void MouseReleased();

private:
	std::unordered_map<std::string, sf::Texture> officeTextures;

	std::vector<sf::Sprite> officeSprites;

	std::vector<Button> officeButtons;

	sf::RenderTexture renderTexture;

	Scroll scroll;

	float scrollOffset;

	sf::Shader perspectiveShader;

	GameDataRef data;
	const sf::Vector2f& mousePos;

	bool lightsOn;
};


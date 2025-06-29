#pragma once
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <GameFwd.h>
#include "Button.h"
#include "ShaderManager.h"
#include "GameView.h"

enum Scroll {
	Left,
	Center,
	Right
};

class Office : public GameView
{
public:
	Office(GameDataRef data, const sf::Vector2f& mousePos);

	// Inherited via GameView
	void Setup() override;
	void Enter() override;
	void HandleInput(const std::optional<sf::Event>& event) override;
	void Update() override;
	void Render() override;
	void CheckButtons() override;

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

	bool lightsOn;



};


#pragma once
#include "GameFwd.h"
#include "ShaderManager.h"
#include "GameView.h"

class Camera : public GameView
{
public:
	Camera(GameDataRef data, const sf::Vector2f& mousePos);
	// Inherited via GameView
	void Setup() override;
	void HandleInput(const std::optional<sf::Event>& event) override;
	void Update() override;
	void Render() override;
	void CheckButtons() override;

	void SetupScaleAndPositions();
private:
	std::unordered_map<std::string, sf::Texture> cameraTextures;
	std::vector<sf::Sprite> cameraSprites;

	std::vector<Button> cameraButtons;
};


#pragma once
#include "GameFwd.h"
#include "ShaderManager.h"
#include "GameView.h"

enum Floor {
	Bottom,
	Top
};

class Camera : public GameView
{
public:
	Camera(GameDataRef data, const sf::Vector2f& mousePos);
	// Inherited via GameView
	void Setup() override;
	void Enter() override;
	void HandleInput(const std::optional<sf::Event>& event) override;
	void Update() override;
	void Render() override;
	void CheckButtons() override;

	void SetupScaleAndPositions();
	void UpdateCam();
	void SetPosReference(std::unordered_map<int, const sf::Vector2i*> posRef);
	void SetMovedReference(std::unordered_map<int, const bool*> movedRef);
	void SetLastRoomReference(std::unordered_map<int, const int*> lastRoomRef);
	void SetSwitchSprite();
	void CheckIfMoved();

private:
	std::unordered_map<std::string, sf::Texture> cameraTextures;
	std::vector<sf::Sprite> cameraSprites;

	std::vector<std::string> mapButtons;
	std::vector<Button> bottomButtons;
	std::vector<Button> topButtons;

	std::vector<std::string> mapHold;
	Button switchButton;
	bool switchHold;

	std::unordered_map<Floor, std::vector<Button>> cameraButtons;
	Floor currentFloor;

	int bottomCamID = 0;
	int topCamID = 7;
	std::string currentButton = "1a";

	std::unordered_map<int, const sf::Vector2i*> enemyPositions;
	std::unordered_map<int, const bool*> enemyMoved;
	std::unordered_map<int, const int*> lastRoom;

};


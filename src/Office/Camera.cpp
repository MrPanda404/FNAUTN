#include "Game.h"
#include "Camera.h"
#include <iostream>

Camera::Camera(GameDataRef data, const sf::Vector2f& mousePos)
	:GameView(data, mousePos),
	currentFloor(Bottom),
	switchHold(false)
{
}

void Camera::Setup()
{
	///Textures and sprites
	{
		mapButtons = {
		"1a", "2a", "3", "4", "5", "6", "7", "1b", "2b", "8"
		};

		AssetManager::LoadTextureGroup(cameraTextures, mapButtons, "textures");

		std::string name = "00000";
		AssetManager::LoadTexture(cameraTextures, name, "cameras");

		mapHold = {
			"alta", "altaHold", "baja", "bajaHold"
		};

		AssetManager::LoadTextureGroup(cameraTextures, mapHold, "textures");

		cameraSprites = {
			sf::Sprite(cameraTextures.at(name)),//0
			sf::Sprite(cameraTextures.at(mapButtons[0])),//1
			sf::Sprite(cameraTextures.at(mapHold[2]))//2
		};

		float scale = 2;
		float windowSize = data->window.getView().getSize().y;
	}
	///Buttons
	{
		bottomButtons = {
			Button("1a", { 323 , 120 }, { 23 , 17 }), //0
			Button("2a", { 129 , 66 }, { 23 , 17 }), //1
			Button("3", { 123 , 46 }, { 23 , 17 }), //2
			Button("4", { 28 , 116 }, { 23 , 17 }), //3
			Button("5", { 2 , 146 }, { 23 , 17 }), //4
			Button("6", { 77 , 165 }, { 23 , 17 }), //5
			Button("7", { 222 , 6 }, { 23 , 17 }), //6
		};

		topButtons = {
			Button("1b", { 221 , 71 }, { 23 , 17 }), //0     7 -> ID
			Button("2b", { 337 , 57 }, { 23 , 17 }), //1     8
			Button("8", { 358 , 90 }, { 23 , 17 }), //2      9
		};

		int id = 0;
		for (auto& button : bottomButtons) {
			///button.GetShape().setFillColor(sf::Color(255, 255, 255, 150));
			button.SetFunction([this, id]() {
				bottomCamID = id;
				currentButton = mapButtons[id];
			});
			id++;
		}

		for (auto& button : topButtons) {
			///button.GetShape().setFillColor(sf::Color(255, 255, 255, 150));
			button.SetFunction([this, id]() {
				topCamID = id;
				currentButton = mapButtons[id];
				});
			id++;
		}

		switchButton = Button("Switch", { 129, 111 }, { 78, 34 });
		///switchButton.GetShape().setFillColor(sf::Color(255, 255, 255, 150));

		switchButton.SetFunction([this]() {
			if (currentFloor == Bottom) {
				currentFloor = Top;
				currentButton = mapButtons[topCamID];
			}
			else{
				currentFloor = Bottom;
				currentButton = mapButtons[bottomCamID];
			}
			});

		cameraButtons[Bottom] = std::move(bottomButtons);
		cameraButtons[Top] = std::move(topButtons);
	}
	///Shaders
	{

	}

	SetupScaleAndPositions();
}

void Camera::Update()
{
	CheckIfMoved();
}

void Camera::Render()
{
	data->window.clear();

	Game::DrawOnWindow(cameraSprites, data->window);

	Game::DrawOnWindow(cameraButtons[currentFloor], data->window);

	data->window.draw(switchButton.GetShape());

	data->window.display();
}

void Camera::CheckButtons()
{
	for (auto& btn : cameraButtons[currentFloor]) {
		if (btn.GetShape().getGlobalBounds().contains(mousePos)) {
			btn.OnClick();
			UpdateCam();
			///std::cout << btn.GetName() << std::endl;
		}
	}

	if (switchButton.GetShape().getGlobalBounds().contains(mousePos) && !switchHold) {
		switchHold = true;
		SetSwitchSprite();
	}
}

void Camera::SetupScaleAndPositions()
{
	float scale = 2;
	float windowSize = data->window.getView().getSize().y;

	sf::Vector2f position = { 30, windowSize - cameraSprites.at(1).getTextureRect().size.y * scale - 30 };

	cameraSprites.at(1).setScale({scale, scale});
	cameraSprites.at(1).setPosition( position );
	cameraSprites.at(2).setScale({scale, scale});
	cameraSprites.at(2).setPosition( position);

	for (auto& button : cameraButtons[Bottom]) {
		button.GetShape().setPosition(button.GetShape().getPosition() * scale); /// <-
		/// Why did we overcomplicate things =C (this works already but still !!!)
		button.GetShape().setScale({ scale, scale });
		button.GetShape().move(position);
	}
	for (auto& button : cameraButtons[Top]) {
		button.GetShape().setPosition(button.GetShape().getPosition() * scale);
		button.GetShape().setScale({ scale, scale });
		button.GetShape().move(position);
	}
	
	
	switchButton.GetShape().setPosition(switchButton.GetShape().getPosition() * scale);
	switchButton.GetShape().setScale({ scale, scale });
	switchButton.GetShape().move(position);

}


void Camera::HandleInput(const std::optional<sf::Event>& event)
{
	if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
		if (sf::Mouse::Button::Left == mousePressed->button) {
			CheckButtons();
		}
	}
	if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
		if (sf::Mouse::Button::Left == mouseReleased->button && switchHold) {
			switchHold = false;
			switchButton.OnClick();
			UpdateCam();
			///std::cout << switchButton.GetName() << std::endl;
		}
	}
}

void Camera::UpdateCam()
{
	std::string camID;
	int currentID;

	if (currentFloor == Bottom){ 
		currentID = bottomCamID; 
	}
	else{ 
		currentID = topCamID; 
	}

	camID += std::to_string(currentID);

	for (int i = 0; i < 4; i++) {
		if (enemyPositions[i]->x == currentID) camID += std::to_string(enemyPositions[i]->y);
		else camID += "0";
	}

	if (auto it = cameraTextures.find(camID); it == cameraTextures.end()) {
		AssetManager::LoadTexture(cameraTextures, camID, "cameras");
	}
	if (auto it = cameraTextures.find(currentButton); it == cameraTextures.end()) {
		AssetManager::LoadTexture(cameraTextures, currentButton, "textures");
	}

	cameraSprites.at(0).setTexture(cameraTextures[camID]);
	cameraSprites.at(1).setTexture(cameraTextures.at(currentButton));

	SetSwitchSprite();
}

void Camera::SetPosReference(std::unordered_map<int, const sf::Vector2i*> posRef)
{
	enemyPositions = posRef;
}

void Camera::SetMovedReference(std::unordered_map<int, const bool*> movedRef)
{
	enemyMoved = movedRef;
}

void Camera::SetLastRoomReference(std::unordered_map<int, const int*> lastRoomRef)
{
	lastRoom = lastRoomRef;
}

void Camera::SetSwitchSprite()
{
	if (switchHold) {

		if (currentFloor == Top) {
			if (auto it = cameraTextures.find(mapHold[1]); it == cameraTextures.end()) {
				AssetManager::LoadTexture(cameraTextures, mapHold[1], "textures");
			}
			cameraSprites.at(2).setTexture(cameraTextures.at(mapHold[1]));
		}
		else {
			if (auto it = cameraTextures.find(mapHold[3]); it == cameraTextures.end()) {
				AssetManager::LoadTexture(cameraTextures, mapHold[3], "textures");
			}
			cameraSprites.at(2).setTexture(cameraTextures.at(mapHold[3]));
		}
	}
	else {
		if (currentFloor == Top) {
			if (auto it = cameraTextures.find(mapHold[0]); it == cameraTextures.end()) {
				AssetManager::LoadTexture(cameraTextures, mapHold[0], "textures");
			}
			cameraSprites.at(2).setTexture(cameraTextures.at(mapHold[0]));
		}
		else {
			if (auto it = cameraTextures.find(mapHold[2]); it == cameraTextures.end()) {
				AssetManager::LoadTexture(cameraTextures, mapHold[2], "textures");
			}
			cameraSprites.at(2).setTexture(cameraTextures.at(mapHold[2]));
		}
	}
}

void Camera::CheckIfMoved()
{
	for (auto moved : enemyMoved) {
		if (*moved.second) {
			int currentID;
			std::cout << "Checking " << moved.first << " Bool: "<< *moved.second << std::endl;

			if (currentFloor == Bottom) {
				currentID = bottomCamID;
			}
			else {
				currentID = topCamID;
			}
			if (enemyPositions[moved.first]->x == currentID || *lastRoom[moved.first] == currentID) {
				std::cout << "Updating cam" << std::endl;
				UpdateCam();
				return;
			}
		}
	}
}

void Camera::Enter()
{
	UpdateCam();
}

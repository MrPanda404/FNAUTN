#include "Game.h"
#include "Camera.h"
#include <iostream>

Camera::Camera(GameDataRef data, const sf::Vector2f& mousePos)
	:GameView(data, mousePos)
{
}

void Camera::Setup()
{
	///Textures and sprites
	{
		std::vector<std::string> mapButtons = {
			"1a", "1b", "2a", "2b", "3", "4", "5", "6", "7", "8"
		};

		AssetManager::LoadTextureGroup(cameraTextures, mapButtons, "textures");

		std::string name = "00000";
		AssetManager::LoadTexture(cameraTextures, name, "cameras");

		std::vector<std::string> mapHold = {
			"alta", "altaHold", "baja", "bajaHold"
		};

		AssetManager::LoadTextureGroup(cameraTextures, mapHold, "textures");

		cameraSprites = {
			sf::Sprite(cameraTextures.at(name)),//0
			sf::Sprite(cameraTextures.at(mapButtons[0])),//1
			sf::Sprite(cameraTextures.at(mapHold[0]))//2
		};

		float scale = 2;
		float windowSize = data->window.getView().getSize().y;
	}
	///Buttons
	{
		cameraButtons = {
			Button("1a", { 323 , 120 }, { 23 , 17 }), //0
			Button("2a", { 129 , 66 }, { 23 , 17 }), //1
			Button("3", { 123 , 46 }, { 23 , 17 }), //2
			Button("4", { 28 , 116 }, { 23 , 17 }), //3
			Button("5", { 2 , 146 }, { 23 , 17 }), //4
			Button("6", { 77 , 165 }, { 23 , 17 }), //5
			Button("7", { 222 , 6 }, { 23 , 17 }), //6
			Button("1b", { 221 , 71 }, { 23 , 17 }), //7
			Button("2b", { 337 , 57 }, { 23 , 17 }), //8
			Button("8", { 358 , 90 }, { 23 , 17 }), //9
		};


		for (auto& button : cameraButtons) {
			button.GetShape().setFillColor(sf::Color(255, 255, 255, 150));
		}
	}
	///Shaders
	{

	}

	SetupScaleAndPositions();
}

void Camera::Update()
{
}

void Camera::Render()
{
	data->window.clear();

	Game::DrawOnWindow(cameraSprites, data->window);
	Game::DrawOnWindow(cameraButtons, data->window);

	data->window.display();
}

void Camera::CheckButtons()
{
	for (auto& btn : cameraButtons) {
		if (btn.GetShape().getGlobalBounds().contains(mousePos)) {
			btn.OnClick();
			std::cout << btn.GetName() << std::endl;
		}
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

	for (auto& button : cameraButtons) { 
		button.GetShape().setPosition(button.GetShape().getPosition() * scale); /// <-
		/// Why did we overcomplicate things =C (this works already but still !!!)
		button.GetShape().setScale({ scale, scale });
		button.GetShape().move(position);
	}
}

void Camera::HandleInput(const std::optional<sf::Event>& event)
{
	if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
		if (sf::Mouse::Button::Left == mousePressed->button) {
			CheckButtons();
		}
	}
}


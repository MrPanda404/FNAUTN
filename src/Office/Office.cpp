#include "Office.h"
#include <iostream>

Office::Office(GameDataRef data, const sf::Vector2f& mousePos)
	:data(data),
	scroll(Center),
	scrollOffset(9),
	mousePos(mousePos),
	lightsOn(false)
{
}

void Office::Setup()
{

	//Textures and Sprites

	std::vector<std::string> name = {
		"L00", "FFFF", "R00", "L01", "0000", "R01"
	};

	for (auto& n : name) {
		AssetManager::LoadTexture(officeTextures, n, "office");
	}
	///Agregar sobrecarga a AssetManager (LoadTextureGroup)
	///Tanto de solo texturas como sin pushear orden.

	for (auto& t : officeTextures) {
		t.second.setSmooth(true);
	}

	officeSprites = {
		sf::Sprite(officeTextures.at(name[0])),
		sf::Sprite(officeTextures.at(name[1])),
		sf::Sprite(officeTextures.at(name[2]))
	};

	officeSprites[0].setPosition({ -1000,0 });
	officeSprites[1].setPosition({ 130,0 });
	officeSprites[2].setPosition({ 1470,0 });




	renderTexture.setSmooth(true);
	if (!renderTexture.resize((sf::Vector2u)data->window.getView().getSize())) {
		std::cerr << "RenderTexture creation failed" << std::endl;
	}


	//Buttons

	officeButtons = {
		Button("LeftDoor", { 844 + officeSprites[0].getPosition().x , 240 }, { 222 , 550 }),//0
		Button("RightDoor", { 2534 + officeSprites[0].getPosition().x , 240 }, { 222 , 550 }),//1
		Button("Light", { 1239 + officeSprites[0].getPosition().x , 154} , {1122 , 427}),//2
	};


	officeButtons[2].SetFunction([this]() {
		std::vector<std::string> name = {
		"L01", "0000", "R01"
		};
		if (officeTextures.count(name[0]) == 0) {
			AssetManager::LoadTexture(officeTextures, name[0], "office");
			AssetManager::LoadTexture(officeTextures, name[1], "office");
			AssetManager::LoadTexture(officeTextures, name[2], "office");
		}
		int i = 0;
		for (auto& s : officeSprites) {
			s.setTexture(officeTextures.at(name[i]), true);
			i++;
		}
		lightsOn = true;
		});

	//Shaders

	ShaderManager::LoadShader(perspectiveShader, "perspective.frag", "src");

	perspectiveShader.setUniform("texture", sf::Shader::CurrentTexture);
}

void Office::Update()
{
	///std::cout << mousePos.x << " - " << mousePos.y << std::endl;

	if (scroll != Center) {
		HorizontalScroll();
	}
}

void Office::Render()
{
	renderTexture.clear();

	for (const auto& s : officeSprites) {
		renderTexture.draw(s);
	}

	renderTexture.display();

	sf::Sprite sprite(renderTexture.getTexture());

	data->window.draw(sprite, &perspectiveShader);

	///Game::DrawOnWindow(test, data->window);
	Game::DrawOnWindow(officeButtons, data->window);
}

void Office::CheckButtons()
{
	for (auto& btn : officeButtons) {
		if (btn.GetShape().getGlobalBounds().contains(mousePos)) {
			btn.OnClick();
			std::cout << btn.GetName() << std::endl;
		}
	}
}

void Office::CheckScroll()
{
	if (mousePos.x > data->window.getView().getSize().x * 0.85f) {
		scroll = Left;
	}
	else if (mousePos.x < data->window.getView().getSize().x * 0.15f) {
		scroll = Right;
	}
	else {
		scroll = Center;
	}
}

void Office::MouseReleased()
{
	if (lightsOn) {
		std::vector<std::string> name = {
			"L00", "FFFF", "R00"
		};

		int i = 0;
		for (auto& s : officeSprites) {
			s.setTexture(officeTextures.at(name[i]), true);
			i++;
		}
	}
}

void Office::HorizontalScroll()
{
	float speed = 0;
	float baseSpeed = 1000;

	switch (scroll)
	{
	case Left:
		if (officeSprites[2].getPosition().x >
			-(officeSprites[2].getTextureRect().size.x - data->window.getView().getSize().x) + scrollOffset) {
			speed = -baseSpeed;
		}
		else return;
		break;
	case Right:
		if (officeSprites[0].getPosition().x < 0 - scrollOffset) {
			speed = baseSpeed;
		}
		else return;
		break;
	default:
		return;
		break;
	}

	speed *= data->dt;

	for (auto& sprite : officeSprites) {
		sprite.move({ speed, 0 });
	}
	for (auto& b : officeButtons) {
		b.GetShape().move({ speed, 0 });
	}
}
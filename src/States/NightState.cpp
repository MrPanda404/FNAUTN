#include "NightState.h"
#include "ShaderManager.h"
#include <iostream>

NightState::NightState(GameDataRef data)
	: scroll(Center),
	scrollOffset(9)
{
	this->data = data;
}

void NightState::Start()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	SetupShaders();
	SetupSprites();
	SetupButtons();	
}

void NightState::HandleInput()
{
    while (const std::optional<sf::Event> event = data->window.pollEvent())
    {
        mousePos = data->window.mapPixelToCoords(sf::Mouse::getPosition(data->window));


        if (event->is<sf::Event::Closed>()) {
            data->window.close();
        }


        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (sf::Keyboard::Key::Escape == keyPressed->code) {
                data->machine.RemoveState();
            }
        }

        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (sf::Mouse::Button::Left == mousePressed->button) {

				for (auto& btn : officeButtons) {
					if (btn.GetShape().getGlobalBounds().contains(mousePos)) {
						btn.OnClick();
						std::cout << btn.GetName() << std::endl;
					}
				}
               
            }
        }
		if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (sf::Mouse::Button::Left == mouseReleased->button) {

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

        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
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
    }
}

void NightState::Update()
{
	if (scroll != Center) {
		HorizontalScroll();
	}
}

void NightState::Render()
{
	data->window.clear();
	renderTexture.clear();

	for (const auto& s : officeSprites) {
		renderTexture.draw(s);
	}

	renderTexture.display();

	sf::Sprite sprite(renderTexture.getTexture());

	data->window.draw(sprite, &perspectiveShader);

	///Game::DrawOnWindow(test, data->window);
	Game::DrawOnWindow(officeButtons, data->window);

	data->window.display();
}

void NightState::Stop()
{
}

void NightState::SetupShaders()
{
	ShaderManager::LoadShader(perspectiveShader, "perspective.frag", "src");
	ShaderManager::LoadShader(gammaShader, "gamma.frag", "src");

	perspectiveShader.setUniform("texture", sf::Shader::CurrentTexture);
}


void NightState::SetupSprites()
{
	std::vector<std::string> name = {
		"L00", "FFFF", "R00"
	};

	AssetManager::LoadTexture(officeTextures, name[0], "office");
	AssetManager::LoadTexture(officeTextures, name[1], "office");
	AssetManager::LoadTexture(officeTextures, name[2], "office");
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

	officeSprites[0].setPosition({-1000,0});
	officeSprites[1].setPosition({ 130,0 });
	officeSprites[2].setPosition({ 1470,0 });


	

	renderTexture.setSmooth(true);
	if (!renderTexture.resize((sf::Vector2u)data->window.getView().getSize())) {
		//std::cerr << "RenderTexture creation failed" << std::endl;
	}

}

void NightState::SetupButtons()
{
	test = {
		Button("Test1", {data->window.getSize().x * 0.85f, 0}, {-(officeSprites[2].getTextureRect().size.x - data->window.getView().getSize().x), 900}),
		Button("Test2", {0, 0}, {data->window.getSize().x * 0.15f, 900})
	};
	//test[0].GetShape().setFillColor(sf::Color(255, 255, 255, 150));
	//test[1].GetShape().setFillColor(sf::Color(255, 255, 255, 150));

	officeButtons = {
		Button("LeftDoor", { 844 + officeSprites[0].getPosition().x , 240 }, { 222 , 550 }),//0
		Button("RightDoor", { 2534 + officeSprites[0].getPosition().x , 240 }, { 222 , 550 }),//1
		Button("Light", { 1239 + officeSprites[0].getPosition().x , 154} , {1122 , 427}),//2
	};

	for (auto& b : officeButtons) {
	//	b.GetShape().setFillColor(sf::Color(255, 255, 255, 150));
	}

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
		});
}

void NightState::HorizontalScroll()
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
		break;
	}

	speed *= data->dt;

	for (auto& sprite : officeSprites) {
		sprite.move({ speed, 0 });
	}
	for (auto& b : officeButtons) {
		b.GetShape().move({speed, 0});
	}
}
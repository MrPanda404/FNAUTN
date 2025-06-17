#include "NightState.h"
#include "ShaderManager.h"

NightState::NightState(GameDataRef data)
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


               
            }
        }

        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            
        }
    }
}

void NightState::Update()
{
	HorizontalScroll();
}

void NightState::Render()
{
	data->window.clear();

	sf::RenderTexture renderTexture;
	renderTexture.setSmooth(true);
	renderTexture.resize((sf::Vector2u)data->window.getView().getSize());
	sf::Sprite sprite(renderTexture.getTexture());
	sprite.setScale({ 1.0, -1.0 });
	sprite.setPosition({ 0., data->window.getView().getSize().y });

	for (auto s : officeSprites) {
		renderTexture.draw(s);
	}
	data->window.draw(sprite, &perspectiveShader);


	//Game::DrawOnWindow(officeSprites, data->window, perspectiveShader);

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
	
	officeSprites = {
		sf::Sprite(officeTextures.at(name[0])),
		sf::Sprite(officeTextures.at(name[1])),
		sf::Sprite(officeTextures.at(name[2]))
	};

	officeSprites[0].setPosition({-1000,0});
	officeSprites[1].setPosition({ 130,0 });
	officeSprites[2].setPosition({ 1470,0 });
}

void NightState::SetupButtons()
{
	
}

void NightState::HorizontalScroll()
{
	float speed = 0;
	float baseSpeed = 1000;
	int offset  = 9;

	sf::Vector2f mousePos = data->window.mapPixelToCoords(sf::Mouse::getPosition(data->window));

	if (mousePos.x > data->window.getSize().x * 0.85 &&
		officeSprites[2].getPosition().x >
		-(officeSprites[2].getTextureRect().size.x - data->window.getView().getSize().x) + offset)
	{
		speed = -baseSpeed;
	}
	if (mousePos.x < data->window.getSize().x * 0.15 &&
		officeSprites[0].getPosition().x < 0 - offset)
	{
		speed = baseSpeed;
	}

	speed *= data->dt;

	for (auto& sprite : officeSprites) {
		sprite.move({ speed, 0 });
	}
}
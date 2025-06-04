#include "MenuState.h"
#include <iostream>

void ApplyParallax(const sf::Vector2f& mousePos, sf::Sprite& sprite, float parallax);
sf::Vector2f CenterMouse(sf::Vector2i mousePos, sf::Vector2u windowSize);

MenuState::MenuState(GameDataRef data)
{
    this->data = data;
}

void MenuState::Start()
{
    SetupSprites();
    SetupButtons();
}

void MenuState::HandleInput()
{
    while (const std::optional<sf::Event> event = data->window.pollEvent()) 
    {
        mousePos = data->window.mapPixelToCoords(sf::Mouse::getPosition(data->window));


        if (event->is<sf::Event::Closed>()) {
            data->window.close();
        }


        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (sf::Keyboard::Key::Escape == keyPressed->code) {
                data->window.close();
            }
        }

        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (sf::Mouse::Button::Left == mousePressed->button) {
                for (const auto& btn : buttons) {
                    if (btn.second.getGlobalBounds().contains(mousePos)) {
                        std::cout << btn.first << std::endl;
                    }
                }
            }
        }

        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            this->mouseMoved = true;
        }
    }
}

void MenuState::Update()
{
    if (mouseMoved) {
        auto centeredMouse = CenterMouse(sf::Mouse::getPosition(data->window), data->window.getSize());
        ApplyParallax(centeredMouse, sprites.at("MenuArtBG"), 100);
        ApplyParallax(centeredMouse, sprites.at("MenuArtSmoke"), 50);
        mouseMoved = false;
    }
}

void MenuState::Render()
{
	data->window.clear();
    for (const std::string& s : drawOrder) {
        data->window.draw(sprites.at(s));
    }
    for (const auto& btn : buttons) {
        data->window.draw(btn.second);
    }
	data->window.display();
}

void MenuState::Stop()
{
}

void MenuState::SetupSprites() 
{
    AssetManager::loadTexture(textures, sprites, "MenuArtBG", "textures", drawOrder);
    AssetManager::loadTexture(textures, sprites, "MenuArtSmoke", "textures", drawOrder);
    AssetManager::loadTexture(textures, sprites, "MenuArtText", "textures", drawOrder);
    AssetManager::loadTexture(textures, sprites, "MenuArtCont", "textures", drawOrder);
    AssetManager::loadTexture(textures, sprites, "MenuArtNoche6", "textures", drawOrder);
    AssetManager::loadTexture(textures, sprites, "MenuArtNocheCustom", "textures", drawOrder);

    AssetManager::CenterSprite(sprites.at("MenuArtBG"));
    AssetManager::CenterSprite(sprites.at("MenuArtSmoke"));

    sprites.at("MenuArtBG").setScale({ 1.05f,1.05f });
    sprites.at("MenuArtSmoke").setScale({ 1.05f,1.05f });
}

void MenuState::SetupButtons() 
{
    AssetManager::loadButton(buttons, "NewGameBtn", { 80,304 }, { 288,64 });
    AssetManager::loadButton(buttons, "ContinueBtn", { 80,416 }, { 288,64 });
    AssetManager::loadButton(buttons, "Night6Btn", { 80,512 }, { 288,64 });
    AssetManager::loadButton(buttons, "CustomNightBtn", { 80,608 }, { 320,64 });
    AssetManager::loadButton(buttons, "ExitBtn", { 46,768 }, { 192,80 });
    AssetManager::loadButton(buttons, "SettingsButton", { 352,768 }, { 304,96 });
}

void ApplyParallax(const sf::Vector2f& mousePos, sf::Sprite& sprite, float parallax) 
{
    sf::FloatRect floatRect = sprite.getLocalBounds();

    float offsetX = floatRect.size.x / (parallax * 4.f);
    float offsetY = floatRect.size.y / (parallax * 4.f);
    float centerX = (floatRect.size.x / 2.f);
    float centerY = (floatRect.size.y / 2.f);

    sf::Vector2f newPosition({
        -mousePos.x / parallax + centerX + offsetX,
        -mousePos.y / parallax + centerY + offsetY,
        });

    std::cout << "Sprite " << parallax << " Vector: " << newPosition.x << ", " << newPosition.y << std::endl;
    std::cout << "MousePos " << mousePos.x << ", " << mousePos.y << std::endl;

    sprite.setPosition(newPosition);
}

sf::Vector2f CenterMouse(sf::Vector2i mousePos, sf::Vector2u windowSize)
{
    return sf::Vector2f({mousePos.x - windowSize.x / 2.f, mousePos.y - windowSize.y / 2.f});
}


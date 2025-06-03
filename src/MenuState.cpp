#include "MenuState.h"
#include <iostream>

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
    while (const std::optional<sf::Event> event = data->window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            data->window.close();
        }


        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (sf::Keyboard::Key::Escape == keyPressed->code) {
                data->window.close();
            }
        }

        if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {

            sf::Vector2f worldPos = data->window.mapPixelToCoords(mousePressed->position);

            if (sf::Mouse::Button::Left == mousePressed->button) {
                for (const auto& btn : buttons) {
                    if (btn.second.getGlobalBounds().contains(worldPos)) {
                        std::cout << btn.first << std::endl;
                    }
                }
            }
        }
    }
}

void MenuState::Update()
{
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

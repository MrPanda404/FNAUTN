#include "NightState.h"
#include "ShaderManager.h"
#include <iostream>

NightState::NightState(GameDataRef data)
    :data(data),
    office(data, mousePos)
{
	
}

void NightState::Start()
{                     
	office.Setup();
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
				office.CheckButtons();
            }
        }
		if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (sf::Mouse::Button::Left == mouseReleased->button) {

				office.MouseReleased();
            }
        }

        if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
			office.CheckScroll();
        }
    }
}

void NightState::Update()
{
	office.Update();
}

void NightState::Render()
{
	data->window.clear();

	office.Render();

	data->window.display();
}

void NightState::Stop()
{
}

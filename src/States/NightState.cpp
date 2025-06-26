#include "Game.h"
#include "NightState.h"
#include "ShaderManager.h"
#include <iostream>

NightState::NightState(GameDataRef data)
    :data(data),
    office(data, mousePos),
    camera(data, mousePos)
{
	
}

void NightState::Start()
{                     
	///office.Setup();
    ///camera.Setup();
    NightManager.AddView((GameViewRef)new Camera(data, mousePos), "camera");
    NightManager.AddView((GameViewRef)new Office(data, mousePos), "office");
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
            if (sf::Keyboard::Key::Space == keyPressed->code) {
                NightManager.SwitchView(player.SwitchState());
            }
        }


        NightManager.HandleViewInput(event);
        ///office.HandleInput(event);
    }
}

void NightState::Update()
{
    NightManager.UpdateView();
	///office.Update();
}

void NightState::Render()
{
    NightManager.RenderView();
	///office.Render();
    //camera.Render();	
}

void NightState::Stop()
{
}

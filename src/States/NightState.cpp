#include "Game.h"
#include "NightState.h"
#include "ShaderManager.h"
#include <iostream>
#include "NightInclude.h"


NightState::NightState(GameDataRef data)
    :data(data),
    office(data, mousePos),
    camera(data, mousePos),
    spacePressed(false),
    allLoaded(false)
{
    Room::SetupRooms();
    enemyManager.AddEnemy((EnemyRef)new Kloster(data->dt));
    enemyManager.AddEnemy((EnemyRef)new Mati(data->dt));
    enemyManager.AddEnemy((EnemyRef)new Maxi(data->dt));
    enemyManager.AddEnemy((EnemyRef)new Vastag(data->dt));
    enemyManager.StartAll();

    camera.SetPosReference(enemyManager.GetPosAndIDs());
    camera.SetMovedReference(enemyManager.GetMovedAndID());
    camera.SetLastRoomReference(enemyManager.GetLastRoomAndID());
}

void NightState::Start()
{
    nightManager.AddView(camera, "camera");
    nightManager.AddView(office, "office");
    allLoaded = true;
}

void NightState::HandleInput()
{
    if (!allLoaded) return;

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

            if (sf::Keyboard::Key::Space == keyPressed->code && !spacePressed) {
                nightManager.SwitchView(player.SwitchState());
                spacePressed = true;
            }
        }

        if (const auto* keyReleased = event->getIf <sf::Event::KeyReleased>()) {
            if (sf::Keyboard::Key::Space == keyReleased->code) {
                spacePressed = false;
            }
        }
        nightManager.HandleViewInput(event);
    }
}

void NightState::Update()
{
    if (!allLoaded) return;
    enemyManager.UpdateAll();
    nightManager.UpdateView();
    enemyManager.ResetMoved();
}

void NightState::Render()
{
    nightManager.RenderView();
}

void NightState::Stop()
{
    
}

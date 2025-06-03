#include "Game.h"
#include "MenuState.h"

Game::Game(sf::VideoMode videomode, std::string title)
{
	data->window.create(videomode, title, sf::State::Fullscreen);
	sf::View view(sf::FloatRect({ 0, 0 }, { 1600, 900 }));
	data->window.setView(view);

	data->machine.addState(StateRef(new MenuState(data)));

	Run();
}

void Game::Run()
{
	data->window.setFramerateLimit(60);

	while (data->window.isOpen())
	{
		data->machine.processStateChanges();

		data->machine.getActiveState()->HandleInput();

		data->machine.getActiveState()->Update();

		data->machine.getActiveState()->Render();
	}
}
#include "Game.h"
#include "MenuState.h"

Game::Game(sf::VideoMode videomode, std::string title)
{
	data->window.create(videomode, title, sf::State::Fullscreen);
	sf::View view(sf::FloatRect({ 0, 0 }, { 1600, 900 }));
	data->window.setView(view);

	data->machine.AddState(StateRef(new MenuState(data)));

	Run();
}

void Game::Run()
{
	sf::Clock deltaTime;

	//data->window.setFramerateLimit(60);
	data->window.setVerticalSyncEnabled(true);


	deltaTime.restart();

	while (data->window.isOpen())
	{
		data->dt = deltaTime.restart().asSeconds();

		data->machine.ProcessStateChanges();

		data->machine.GetActiveState()->HandleInput();

		data->machine.GetActiveState()->Update();

		data->machine.GetActiveState()->Render();
	}
}

void Game::DrawOnWindow(std::unordered_map<std::string, sf::Sprite>& sprites, std::vector<std::string>& v, sf::RenderWindow& window)
{
	for (std::string s : v) {
		window.draw(sprites.at(s));
	}
}

void Game::DrawOnWindow(std::vector<Button> buttons, sf::RenderWindow& window)
{
	for (const auto& btn : buttons) {
		window.draw(btn.GetShape());
	}
}

void Game::DrawOnWindow(std::vector<sf::Sprite> sprites, sf::RenderWindow& window)
{
	for (const auto& s : sprites) {
		window.draw(s);
	}
}

void Game::DrawOnWindow(std::vector<sf::Sprite> sprites, sf::RenderWindow& window, sf::Shader& shader)
{
	for (const auto& s : sprites) {
		window.draw(s, &shader);
	}
}

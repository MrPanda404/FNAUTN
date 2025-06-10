#pragma once
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "Button.h"

struct GameData {
	sf::RenderWindow window;
	StateMachine machine;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(sf::VideoMode videomode, std::string title);

	static void DrawOnWindow(
		std::unordered_map<std::string, sf::Sprite>& sprites,
		std::vector<std::string>& v,
		sf::RenderWindow& window);

	static void DrawOnWindow(
		std::vector<Button> buttons,
		sf::RenderWindow& window);


private:
	sf::Clock clock;
	GameDataRef data = std::make_shared<GameData>();

	void Run();
};


#pragma once
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"

struct GameData {
	sf::RenderWindow window;
	StateMachine machine;
	//Agregar asset manager?
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(sf::VideoMode videomode, std::string title);

private:
	sf::Clock clock;
	GameDataRef data = std::make_shared<GameData>();

	void Run();
};


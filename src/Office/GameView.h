#pragma once
#include "GameFwd.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>


class GameView
{
public:
	GameView(GameDataRef data, const sf::Vector2f& mousePos) : data(data), mousePos(mousePos) {};
	virtual ~GameView() = default;
	virtual void Setup() = 0;
	virtual void Enter() = 0;
	virtual void HandleInput(const std::optional<sf::Event>& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void CheckButtons() = 0;
protected:
	GameDataRef data;
	const sf::Vector2f& mousePos;
};


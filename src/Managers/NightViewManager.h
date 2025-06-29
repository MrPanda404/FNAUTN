#pragma once
#include "GameView.h"
#include <memory>
#include <unordered_map>
#include <string>
#include "SFML/Window/Event.hpp"
#include <optional>

typedef GameView& GameViewRef;

class NightViewManager
{
public:
	NightViewManager();
	~NightViewManager() = default;
	void AddView(GameViewRef view, std::string name);
	void HandleViewInput(const std::optional<sf::Event>& event);
	void UpdateView();
	void RenderView();
	void SwitchView(std::string viewName);
private:
	std::unordered_map<std::string ,GameViewRef> views;
	std::string currentView;
};


#include "NightViewManager.h"

NightViewManager::NightViewManager()
{
}

void NightViewManager::AddView(GameViewRef view, std::string name)
{
	view.Setup();
	views.insert({name, view});
	currentView = name;
}

void NightViewManager::HandleViewInput(const std::optional<sf::Event>& event)
{
	if (auto it = views.find(currentView); it != views.end()) {
		it->second.HandleInput(event);
	}
}

void NightViewManager::UpdateView()
{
	if (auto it = views.find(currentView); it != views.end()) {
		it->second.Update();
	}
}

void NightViewManager::RenderView()
{
	if (auto it = views.find(currentView); it != views.end()) {
		it->second.Render();
	}
}

void NightViewManager::SwitchView(std::string viewName)
{
	if (views.find(viewName) != views.end() ) {
		currentView = viewName;
	}
}

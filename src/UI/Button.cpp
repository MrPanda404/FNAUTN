#include "Button.h"


Button::Button(std::string name, sf::Vector2f position, sf::Vector2f size)
{
	this->name = name;
	rectangle.setPosition(position);
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color(255, 255, 255, 0));
}

void Button::SetFunction(const std::function<void()> function)
{
	this->function = function;
}

void Button::OnClick()
{
	if (function) {
		function();
	}
}

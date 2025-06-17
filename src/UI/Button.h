#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>
#include <string>

class Button
{
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	Button() {};
	
	/// <summary>
	/// Button constructor.
	/// Initializes the button with a name, position, and size.
	/// Default color is transparent.
	/// </summary>
	/// <param name="name">The name of the button.</param>
	/// <param name="position">The position of the button (x, y coordinates).</param>
	/// <param name="size">The size of the button (width and height).</param>
	Button(std::string name,sf::Vector2f position, sf::Vector2f size);

	/// <summary>
	/// Sets the function of the Button.
	/// </summary>
	/// <param name="function">New function for the button.</param>
	void SetFunction(const std::function<void()> function);

	/// <summary>
	/// Executes the button's current function if it exists (not null).
	/// </summary>
	void OnClick();

	/// <summary>
	/// Returns a reference to the RectangleShape of the button.
	/// This allows modification of the shape (position, size, color, etc.).
	/// </summary>
	/// <returns>Reference to the button's RectangleShape (modifiable).</returns>
	sf::RectangleShape& GetShape() { return rectangle; }

	/// <summary>
	/// Returns a const reference to the RectangleShape of the button.
	/// This does not allow modification of the shape.
	/// </summary>
	/// <returns>Const reference to the button's RectangleShape (read-only).</returns>
	const sf::RectangleShape& GetShape() const { return rectangle; };

	/// <summary>
	/// Sets a new name of the button.
	/// </summary>
	/// <param name="name">New name for the button.</param>
	void SetName(const std::string& name) { this->name = name; }

	/// <summary>
	/// Returns a read-only reference to the button's name.
	/// </summary>
	/// <returns>Const reference to the button's name string.</returns>
	const std::string& GetName() const { return name; };
private:

	sf::RectangleShape rectangle;
	std::function<void()> function;
	std::string name;
};


#pragma once
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	static std::pair<std::string, sf::Sprite> loadTexture(
		std::unordered_map<std::string, sf::Texture>& textures,
		const std::string& name,
		const std::string& folder, std::vector<std::string>& v);

	static void loadTexture(
		std::unordered_map<std::string, sf::Texture>& textures, std::unordered_map<std::string, sf::Sprite>& sprites,
		const std::string& name,
		const std::string& folder, std::vector<std::string>& v);

	static void loadTexture(sf::Texture texture, std::string name, std::string folder);
	
	static void loadButton(
		std::unordered_map<std::string, sf::RectangleShape>& buttons,
		const std::string& name,
		const sf::Vector2f& position,
		const sf::Vector2f& size);
};


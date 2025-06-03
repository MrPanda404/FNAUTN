#include "AssetManager.h"
#include <iostream>

std::pair<std::string, sf::Sprite> AssetManager::loadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	const std::string& name,
	const std::string& folder, std::vector<std::string>& v)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load "<< name << std::endl;
	}

	v.push_back(name);

	return { name, sf::Sprite(textures[name]) };
}

void AssetManager::loadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	std::unordered_map<std::string, sf::Sprite>& sprites,
	const std::string& name,
	const std::string& folder, std::vector<std::string>& v)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}

	v.push_back(name);

	sprites.insert({name, sf::Sprite(textures[name])});
}

void AssetManager::loadTexture(sf::Texture texture, std::string name, std::string folder)
{
	if(!texture.loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}
}

void AssetManager::loadButton(
	std::unordered_map<std::string, sf::RectangleShape>& buttons,
	const std::string& name,
	const sf::Vector2f& position,
	const sf::Vector2f& size)
{
	sf::RectangleShape rs(size);
	rs.setPosition(position);
	rs.setFillColor(sf::Color(255, 255, 255, 150));

	buttons.insert({ name, rs });

	return;
}



#include "AssetManager.h"
#include <iostream>

std::pair<std::string, sf::Sprite> AssetManager::LoadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	const std::string& name,
	const std::string& folder,
	std::vector<std::string>& v)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load "<< name << std::endl;
	}

	v.push_back(name);

	return { name, sf::Sprite(textures[name]) };
}

void AssetManager::LoadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	std::unordered_map<std::string, sf::Sprite>& sprites,
	const std::string& name,
	const std::string& folder,
	std::vector<std::string>& v)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}

	v.push_back(name);

	sprites.insert({name, sf::Sprite(textures[name])});
}

void AssetManager::LoadTexture(sf::Texture& texture,const std::string& name, const std::string& folder)
{
	if(!texture.loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}
}

void AssetManager::LoadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	const std::string& name,
	const std::string& folder)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}

}

void AssetManager::LoadTexture(
	std::unordered_map<std::string, sf::Texture>& textures,
	std::unordered_map<std::string, sf::Sprite>& sprites,
	const std::string& name,
	const std::string& folder)
{
	if (!textures[name].loadFromFile(folder + "/" + name + ".png")) {
		std::cout << "Failed to load " << name << std::endl;
	}

	sprites.insert({ name, sf::Sprite(textures[name]) });
}

void AssetManager::LoadTextureGroup(
	std::unordered_map<std::string, sf::Texture>& textures,
	std::unordered_map<std::string, sf::Sprite>& sprites,
	const std::vector<std::string>& names,
	const std::string& folder)
{
	for (const std::string& name : names) {
		LoadTexture(textures, sprites, name, folder);
	}
}

void AssetManager::CenterSprites(std::unordered_map<std::string, sf::Sprite>& sprites)
{
	for (auto& s : sprites) {
		sf::FloatRect localBounds = s.second.getLocalBounds();
		s.second.setOrigin({ localBounds.size.x / 2.f, localBounds.size.y / 2.f });
	}
}

void AssetManager::CenterSprite(sf::Sprite& sprite)
{
	sf::FloatRect localBounds = sprite.getLocalBounds();
	sprite.setOrigin({ localBounds.size.x / 2.f, localBounds.size.y / 2.f });
}
#pragma once
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	/// <summary>
	/// Loads a texture into the provided textures map using the given name as key,
	/// adds its name to the vector,
	/// and returns a pair containing the texture name and a sprite using the texture.
	/// </summary>
	/// <param name="textures">Map where the textures are stored.</param>
	/// <param name="name">Name of the texture to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	/// <param name="drawOrder">Vector to append the texture name.</param>
	/// <returns>A pair containing the texture name and a sprite using the texture.</returns>
	static std::pair<std::string, sf::Sprite> LoadTexture(
		std::unordered_map<std::string, sf::Texture>& textures,
		const std::string& name,
		const std::string& folder,
		std::vector<std::string>& drawOrder);

	/// <summary>
	/// Loads a texture into the provided textures map using the given name as key,
	/// adds its name to the vector,
	/// and inserts a sprite using the loaded texture and name into the sprites map.
	/// </summary>
	/// <param name="textures">Map where the textures are stored.</param>
	/// <param name="sprites">Map where the sprites are stored.</param>
	/// <param name="name">Name of the texture to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	/// <param name="drawOrder">Vector to append the texture name.</param>
	static void LoadTexture(
		std::unordered_map<std::string, sf::Texture>& textures,
		std::unordered_map<std::string, sf::Sprite>& sprites,
		const std::string& name,
		const std::string& folder,
		std::vector<std::string>& drawOrder);

	/// <summary>
	/// Loads a texture into the provided Texture object. 
	/// </summary>
	/// <param name="texture">Texture object to load into.</param>
	/// <param name="name">Name of the texture to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	static void LoadTexture(sf::Texture& texture, const std::string& name, const std::string& folder);

	/// <summary>
	/// Loads a texture into the provided textures map using the given name as key.
	/// </summary>
	/// <param name="textures">Map where the textures are stored.</param>
	/// <param name="name">Name of the texture to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	static void LoadTexture(
		std::unordered_map<std::string, sf::Texture>& textures,
		const std::string& name,
		const std::string& folder);

	/// <summary>
	/// Loads a texture into the provided textures map using the given name as key,
	/// and inserts a sprite using the loaded texture and name into the sprites map.
	/// </summary>
	/// <param name="textures">Map where the textures are stored.</param>
	/// <param name="sprites">Map where the sprites are stored.</param>
	/// <param name="name">Name of the texture to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	static void LoadTexture(
		std::unordered_map<std::string, sf::Texture>& textures,
		std::unordered_map<std::string, sf::Sprite>& sprites,
		const std::string& name,
		const std::string& folder);

	/// <summary>
	/// Loads a group of textures into the provided textures map using the names as key,
	/// and adds corresponding sprites to the provided sprites map using the loaded textures and names.
	/// </summary>
	/// <param name="textures">Map where the texture are stored.</param>
	/// <param name="sprites">Map where the sprites are stored.</param>
	/// <param name="names">List of textures names to load and use as key.</param>
	/// <param name="folder">Folder path of the texture.</param>
	static void LoadTextureGroup(
		std::unordered_map<std::string, sf::Texture>& textures,
		std::unordered_map<std::string, sf::Sprite>& sprites,
		const std::vector<std::string>& names,
		const std::string& folder
	);

	/// <summary>
	/// Sets the origin of each sprite in the provided map to its center.
	/// </summary>
	/// <param name="sprites">Map where the sprites are stored.</param>
	static void CenterSprites(std::unordered_map <std::string, sf::Sprite>& sprites);

	/// <summary>
	/// Sets the origin of the provided sprite to its center.
	/// </summary>
	/// <param name="sprite">Sprite object to center its origin to.</param>
	static void CenterSprite(sf::Sprite& sprite);
};


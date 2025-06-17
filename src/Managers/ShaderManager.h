#pragma once
#include "SFML/Graphics/Shader.hpp"

class ShaderManager
{
public:
	static void LoadShader(sf::Shader& shader,const std::string& name,const std::string& folder);
};


#include "ShaderManager.h"
#include <iostream>

void ShaderManager::LoadShader(sf::Shader& shader,const std::string& name, const std::string& folder)
{
	if (!shader.loadFromFile(folder + "/" + name, sf::Shader::Type::Fragment)) {
		std::cerr << "failed to load " << name << std::endl;
	}
}

#include "Game.h"
#include <iostream>


int main()
{
    if (!sf::Shader::isAvailable())
    {
        std::cerr << "Shaders not supported on current system, aborting" << std::endl;
        return EXIT_FAILURE;
    }

	Game game(sf::VideoMode::getDesktopMode(), "FNAUTN");

	return 0;
}
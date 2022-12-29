#include "Pacman.h"
#include "Helper.h"

void Pacman::Init(const sf::Vector2f& pacmanSpawn)
{
	setPosition(pacmanSpawn);
	setTexture(&textures::pacmanTexture);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
}

#include "Ghost.h"
#include "Helper.h"

void Ghost::Init(const sf::Vector2f& ghostSpawn)
{
	setPosition(ghostSpawn);
	setTexture(&textures::ghostTexture);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
}

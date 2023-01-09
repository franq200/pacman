#include "Acceleration.h"
#include "Helper.h"

void Acceleration::Init(sf::Vector2f pos)
{
	setFillColor(sf::Color::Green);
	setSize({ size::cellSize, size::cellSize });
	setPosition(pos);
}
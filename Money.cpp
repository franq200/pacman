#include "Money.h"
#include "Helper.h"

void Money::Init(sf::Vector2f pos)
{
	setFillColor(sf::Color::Yellow);
	setSize({size::cellSize, size::cellSize});
	setPosition(pos);
}
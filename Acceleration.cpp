#include "Acceleration.h"
#include "Helper.h"

void Acceleration::Init(sf::Vector2f pos)
{
	setFillColor(sf::Color::Green);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
	setPosition(pos);
	m_expiredClock.restart();
}
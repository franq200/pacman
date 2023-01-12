#include "Acceleration.h"
#include "Helper.h"

void Acceleration::Init(sf::Vector2f pos)
{
	setFillColor(sf::Color::Blue);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
	setPosition(pos);
	m_expiredClock.restart();
}

void Acceleration::MakeAction(Pacman &pacman)
{
	pacman.SpeedUp();
}

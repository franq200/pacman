#include "Money.h"
#include "Helper.h"

void Money::Init(sf::Vector2f pos)
{
	setFillColor(sf::Color::Yellow);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
	setPosition(pos);
	m_expiredClock.restart();
}

void Money::MakeAction(Pacman& pacman)
{
	m_score++;
}

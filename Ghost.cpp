#include "Ghost.h"
#include "Helper.h"

void Ghost::Init(const sf::Vector2f& ghostSpawn)
{
	setPosition(ghostSpawn);
	setTexture(&textures::ghostTexture);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
	m_moveClock.restart();
}

void Ghost::MakeMove()
{
	if (m_moveClock.getElapsedTime() > sf::milliseconds(speed::ghostSpeed))
	{
		//Moveable::MakeMove(Direction::down);
		// add A*
		m_moveClock.restart();
	}
}

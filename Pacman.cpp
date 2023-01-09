#include "Pacman.h"
#include "Helper.h"

void Pacman::Init(const sf::Vector2f& pacmanSpawn)
{
	setPosition(pacmanSpawn);
	setTexture(&textures::pacmanTexture);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
}

void Pacman::SetSpeed(bool speed)
{
	if(m_speedClock.getElapsedTime() == sf::seconds(4) && speed::pacmanSpeed == 100.f)
	{
		speed::pacmanSpeed = 175.f;
	}
	else if (speed && speed::pacmanSpeed != 100.f)
	{
		speed::pacmanSpeed = 100.f;
		m_speedClock.restart();
	}
	else
	{
		speed::pacmanSpeed = 175.f;
	}
}

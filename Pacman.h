#pragma once
#include "Moveable.h"

class Pacman : public Moveable 
{
public:
	void Init(const sf::Vector2f& pacmanSpawn);
	void SpeedUp();
	void TryChangeSpeed();
private:
	sf::Clock m_speedClock;
};
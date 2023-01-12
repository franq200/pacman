#pragma once
#include <SFML/Graphics.hpp>
#include "Pacman.h"

class Bonus : public sf::RectangleShape
{
public:
	void virtual Init(sf::Vector2f pos) = 0;
	bool IsAlive();
	void TryMakeAction(Pacman &pacman);
	void virtual MakeAction(Pacman &pacman) = 0;
	static const unsigned m_spawnPeriod = 5;
protected:
	bool m_isAlive = true;
	sf::Clock m_expiredClock;
};
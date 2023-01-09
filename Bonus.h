#pragma once
#include <SFML/Graphics.hpp>

class Bonus : public sf::RectangleShape
{
public:
	void virtual Init(sf::Vector2f pos) = 0;
	bool IsAlive() const;

	static const unsigned m_spawnPeriod = 5;
protected:
	sf::Clock m_expiredClock;
};
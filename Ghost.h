#pragma once
#include "Moveable.h"
#include "SFML/System.hpp"

class Ghost : public Moveable
{
public:
	void Init(const sf::Vector2f& ghostSpawn);
	void MakeMove();
private:
	sf::Clock m_moveClock;
	std::vector<sf::Vector2f> m_pathToPacman;
	// add vector<positons> another container??
	// recalculate algorithm after 3 moves (counter)
};
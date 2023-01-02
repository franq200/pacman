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
	// to do: add timer for move
	// add vector<positons> another container??
	// recalculate algorithm after 3 moves (counter)
};
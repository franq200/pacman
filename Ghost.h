#pragma once
#include "Moveable.h"
#include "SFML/System.hpp"

class Ghost : public Moveable
{
public:
	void Init(const sf::Vector2f& ghostSpawn);
	void MakeMove(const sf::Vector2f& pacmanPos, const std::vector<std::vector<bool>>& map);
private:
	sf::Clock m_moveClock;
	std::vector<sf::Vector2f> m_pathToPacman;
	int m_movesCounter = 0;
	std::vector<sf::Vector2f> m_path;
	// add vector<positons> another container??
	// recalculate algorithm after 3 moves (counter)
};
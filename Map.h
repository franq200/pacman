#pragma once
#include "Cell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Map
{
public:
	void ReadMap(std::string path);
	void Draw(sf::RenderWindow& window);
	std::vector<sf::Vector2f> GetGhostsSpawns() const;
	sf::Vector2f GetPacmanSpawn() const;
private:
	sf::Vector2f m_pacmanSpawn;
	std::vector<sf::Vector2f> m_ghostsSpawn;
	std::vector<std::vector<Cell>> m_map;
};
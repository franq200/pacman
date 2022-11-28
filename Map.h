#pragma once
#include "Cell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Map
{
public:
	void Init(std::string path);
	void Draw(sf::RenderWindow& window);
private:
	void ReadMap(std::string path);
	sf::Vector2f m_pacmanSpawn;
	std::vector<sf::Vector2f> m_ghostsSpawn;
	std::vector<std::vector<Cell>> m_map;
};
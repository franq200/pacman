#pragma once
#include "Cell.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Map
{
public:
	bool ReadAndValidateMap(std::string path);
	void Draw(sf::RenderWindow& window);
	const std::vector<sf::Vector2f>& GetGhostsSpawns() const;
	sf::Vector2f GetPacmanSpawn() const;
	bool IsBlockedCell(std::size_t x, std::size_t y) const;
	std::vector<std::vector<bool>> GetRawMap() const;
	sf::Vector2f GetRandomFreePos(sf::Vector2f pacmanPos);
private:
	sf::Vector2f m_pacmanSpawn = {-1.f, -1.f};
	std::vector<sf::Vector2f> m_ghostsSpawn;
	std::vector<std::vector<Cell>> m_map;
};
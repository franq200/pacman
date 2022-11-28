#include "Map.h"
#include "Helper.h"
#include <fstream>

void Map::Draw(sf::RenderWindow& window)
{
	for (int row = 0; row < m_map.size(); ++row)
	{
		for (int column = 0; column < m_map[row].size(); ++column)
		{
			window.draw(m_map[row][column]);
		}
	}
}

void Map::ReadMap(std::string path)
{
	std::ifstream file;
	file.open(path);
	std::string line;

	while (getline(file, line))
	{
		std::vector<Cell> row;
		for (int i = 0; i < line.size(); ++i)
		{
			if (line[i] == 'p')
			{
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
				m_pacmanSpawn = { static_cast<float>(row.size() * size::cellSize), static_cast<float>(m_map.size() * size::cellSize) };
			}
			else if (line[i] == 'g')
			{
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
				m_ghostsSpawn.push_back({ static_cast<float>(row.size() * size::cellSize), static_cast<float>(m_map.size() * size::cellSize) });
			}
			else if (line[i] == '*')
			{
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::blocked));
			}
			else
			{
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
			}
		}
		m_map.push_back(row);
	}
}
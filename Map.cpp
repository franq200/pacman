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

const std::vector<sf::Vector2f>& Map::GetGhostsSpawns() const
{
	return m_ghostsSpawn;
}

sf::Vector2f Map::GetPacmanSpawn() const
{
	return m_pacmanSpawn;
}

bool Map::IsBlockedCell(std::size_t x, std::size_t y) const
{
	return m_map[y][x].GetState() == State::blocked;
}

const std::vector<std::vector<bool>>& Map::GetRawMap() const
{
	return m_rawMap;
}

sf::Vector2f Map::GetRandomFreePos(sf::Vector2f pacmanPos)
{
	std::vector<sf::Vector2f> freePositions;
	for (int y = 0; y < m_map.size(); ++y)
	{
		for (int x = 0; x < m_map[y].size(); ++x)
		{
			if (m_map[x][y].GetState() == State::free && position::CalculateDistance({ x, y }, {pacmanPos.x, pacmanPos.y}) > 4)
			{
				freePositions.push_back({ static_cast<float>(x), static_cast<float>(y) });
			}
		}
	}
	
	return freePositions.at(position::RandomNum(0, freePositions.size() - 1));
}

bool Map::ReadAndValidateMap(std::string path)
{
	std::ifstream file;
	file.open(path);
	std::string line;

	while (getline(file, line))
	{
		std::vector<Cell> row;
		std::vector<bool> rawRow;
		for (int i = 0; i < line.size(); ++i)
		{
			if (line[i] == 'p')
			{
				rawRow.push_back(true);
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
				m_pacmanSpawn = { static_cast<float>((row.size() - 1) * size::cellSize), static_cast<float>(m_map.size() * size::cellSize) };
			}
			else if (line[i] == 'g')
			{
				rawRow.push_back(true);
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
				m_ghostsSpawn.push_back({ static_cast<float>((row.size() - 1) * size::cellSize), static_cast<float>(m_map.size() * size::cellSize) });
			}
			else if (line[i] == '*')
			{
				rawRow.push_back(false);
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::blocked));
			}
			else
			{
				rawRow.push_back(true);
				row.push_back(Cell(static_cast<int>(row.size()) * size::cellSize, static_cast<int>(m_map.size()) * size::cellSize, State::free));
			}
		}

		m_rawMap.push_back(rawRow);
		m_map.push_back(row);
	}

	if (m_map.size() < 2 || m_pacmanSpawn == position::invalidPosition)
		return false;

	return true;
}
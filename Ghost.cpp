#include "Ghost.h"
#include "Helper.h"

void Ghost::Init(const sf::Vector2f& ghostSpawn)
{
	setPosition(ghostSpawn);
	setTexture(&textures::ghostTexture);
	setSize({ size::cellSize - size::cellOutlineThickness, size::cellSize - size::cellOutlineThickness });
	m_moveClock.restart();
}

void Ghost::MakeMove(const sf::Vector2f& pacmanPos, const std::vector<std::vector<bool>>& map)
{
	if (m_moveClock.getElapsedTime() > sf::milliseconds(speed::ghostSpeed))
	{
		if (m_movesCounter == 0)
		{
			m_path = FindShortestPath(position::GetMapIndexesFromPosition(pacmanPos), position::GetMapIndexesFromPosition(getPosition()), map);
		}
		if (!m_path.empty())
		{
			setPosition(position::GetPositionFromMapIndexes({ static_cast<float>(m_path[m_path.size()-1].x), static_cast<float>(m_path[m_path.size() - 1].y)}));
			m_path.pop_back();
		}
		if (m_movesCounter == 2)
		{
			m_movesCounter = 0;
		}
		else
		{
			m_movesCounter++;
		}
		m_moveClock.restart();
	}
}
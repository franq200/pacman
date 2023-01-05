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
		auto path = position::FindShortestPath(position::GetMapIndexesFromPosition(pacmanPos), position::GetMapIndexesFromPosition(getPosition()), map);
		if (!path.empty())
		{
			setPosition(position::GetPositionFromMapIndexes({ static_cast<float>(path[0].x), static_cast<float>(path[0].y) }));
		}

		m_moveClock.restart();
	}
}

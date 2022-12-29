#include "Helper.h"

namespace size
{
	int windowSize = 800;
	int cellsNum = 15;
	int cellSize = windowSize / cellsNum;
	float cellOutlineThickness = 3.f;
}

namespace speed
{
	int pacmanSpeed = 175;
	int ghostSpeed = 175;
}

namespace textures
{
	sf::Texture pacmanTexture;
	sf::Texture ghostTexture;
}

namespace position
{
	sf::Vector2f invalidPosition = { -1.f, -1.f };

	std::pair<std::size_t, std::size_t> GetMapIndexesFromPosition(const sf::Vector2f& pos)
	{
		return { static_cast<size_t>(pos.x / size::cellSize), static_cast<size_t>(pos.y / size::cellSize) };
	}

	sf::Vector2f GetPositionFromMapIndexes(const std::pair<std::size_t, std::size_t>& mapIndexes)
	{
		return sf::Vector2f(mapIndexes.first * static_cast<float>(size::cellSize), mapIndexes.second * static_cast<float>(size::cellSize));
	}
}
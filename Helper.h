#pragma once
#include <SFML/Graphics.hpp>

namespace size
{
	extern int windowSize;
	extern int cellsNum;
	extern int cellSize;
	extern float cellOutlineThickness;
}

namespace speed
{
	extern int pacmanSpeed;
	extern int ghostSpeed;
}

namespace textures
{
	extern sf::Texture pacmanTexture;
	extern sf::Texture ghostTexture;
}

namespace position
{
	std::pair<std::size_t, std::size_t> GetMapIndexesFromPosition(const sf::Vector2f&);
	sf::Vector2f GetPositionFromMapIndexes(const std::pair<std::size_t, std::size_t>&);
}
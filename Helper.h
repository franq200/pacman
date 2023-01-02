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
	extern sf::Vector2f invalidPosition;

	std::pair<std::size_t, std::size_t> GetMapIndexesFromPosition(const sf::Vector2f&);
	sf::Vector2f GetPositionFromMapIndexes(const std::pair<std::size_t, std::size_t>&);

	struct AStarData
	{
		double m_totalCost = std::numeric_limits<double>::max();
		double m_moveCost = 0.0; // g
		double m_distanceCost = std::numeric_limits<double>::max();
		std::pair <std::size_t, std::size_t> m_parentPos = { -1.f, -1.f };
		std::pair <std::size_t, std::size_t> m_pos = { 0, 0 };
	};

	std::vector<sf::Vector2f> FindShortestPath(sf::Vector2f pacmanPos, sf::Vector2f ghostPos, std::vector<std::vector<bool>> map);
	double CalculateDistance(std::pair<int, int> start, std::pair<int, int> end);
	bool CheckMove(std::vector<std::vector<AStarData>>& data, std::vector<AStarData>& openList, std::pair<int, int> endPos, std::pair<int, int> movePos, AStarData currentData, std::pair<int, int> currentPos, std::vector<std::vector<bool>> map);
}
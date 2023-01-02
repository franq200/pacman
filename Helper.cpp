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
	int ghostSpeed = 350;
}

namespace textures
{
	sf::Texture pacmanTexture;
	sf::Texture ghostTexture;
}

namespace position
{
	bool CheckMove(std::vector<std::vector<AStarData>>& data, std::vector<AStarData>& openList, std::pair<int, int> endPos, std::pair<int, int> movePos, AStarData currentData, std::pair<int, int> currentPos, std::vector<std::vector<bool>> map)
	{
		if (!(currentPos.first >= data.size() || currentPos.first < 0 || currentPos.second >= data.size() || currentPos.second < 0 || map[currentPos.first][currentPos.second] == false))
		{
			if (movePos == endPos)
			{
				data[movePos.first][movePos.second].m_parentPos = currentPos;
				return false;
			}
			else
			{
				double lastCost = data[movePos.first][movePos.second].m_totalCost; // 11
				if (currentData.m_moveCost + 1 + CalculateDistance(movePos, endPos) < lastCost)
				{
					data[movePos.first][movePos.second].m_moveCost = currentData.m_moveCost;
					data[movePos.first][movePos.second].m_distanceCost = CalculateDistance(movePos, endPos);
					data[movePos.first][movePos.second].m_totalCost = data[movePos.first][movePos.second].m_moveCost + data[movePos.first][movePos.second].m_distanceCost;
					data[movePos.first][movePos.second].m_parentPos = currentPos;
					openList.push_back(data[movePos.first][movePos.second]);
				}
				// newCost = moveCost + distanceCost;
			}
		}
		return true;
	}

	double CalculateDistance(std::pair<int, int> start, std::pair<int, int> end)
	{
		double xPos = std::abs(start.first - end.first);
		double yPos = std::abs(start.second - end.second);
		return xPos + yPos;
	}

	sf::Vector2f invalidPosition = { -1.f, -1.f };

	std::pair<std::size_t, std::size_t> GetMapIndexesFromPosition(const sf::Vector2f& pos)
	{
		return { static_cast<size_t>(pos.x / size::cellSize), static_cast<size_t>(pos.y / size::cellSize) };
	}

	sf::Vector2f GetPositionFromMapIndexes(const std::pair<std::size_t, std::size_t>& mapIndexes)
	{
		return sf::Vector2f(mapIndexes.first * static_cast<float>(size::cellSize), mapIndexes.second * static_cast<float>(size::cellSize));
	}

	std::vector<sf::Vector2f> FindShortestPath(std::pair <std::size_t, size_t> pacmanIndex, std::pair <std::size_t, size_t>  ghostIndex, std::vector<std::vector<bool>> map)
	{
		std::vector<AStarData> openList;

		std::vector<std::vector<AStarData>> data;
		data.resize(map.size());
		for (int i = 0; i < data.size(); ++i)
		{
			data[i].resize(map[i].size());
		}

		for (int x = 0; x < data.size(); ++x)
		{
			for (int y = 0; y < data[x].size(); ++y)
			{
				data[x][y].m_pos = { x, y };
			}
		}

		data[ghostIndex.first][ghostIndex.second].m_distanceCost = CalculateDistance(pacmanIndex, ghostIndex);
		data[ghostIndex.first][ghostIndex.second].m_totalCost = data[ghostIndex.first][ghostIndex.second].m_moveCost + data[ghostIndex.first][ghostIndex.second].m_distanceCost;
		openList.push_back(data[ghostIndex.first][ghostIndex.second]);

		while (!openList.empty())
		{
			std::sort(openList.begin(), openList.end(), [](const auto& first, const auto& second) {return first.m_totalCost > second.m_totalCost; }); // std::set O(n2), O(n), O(logn), O(1)
			AStarData currentData = openList.back();
			openList.pop_back();
			std::pair<int, int> currentPos = currentData.m_pos;

			std::pair<int, int> leftPos = { currentPos.first - 1, currentPos.second };
			if (!CheckMove(cells, openList, endPos, leftPos, currentCell, currentCellPos))
			{
				GetResult(cells, endPos, startPos);
				break;
			}

			std::pair<int, int> rightPos = { currentCellPos.first + 1, currentCellPos.second };
			if (!CheckMove(cells, openList, endPos, rightPos, currentCell, currentCellPos))
			{
				GetResult(cells, endPos, startPos);
				break;
			}

			std::pair<int, int> upPos = { currentCellPos.first, currentCellPos.second - 1 };
			if (!CheckMove(cells, openList, endPos, upPos, currentCell, currentCellPos))
			{
				GetResult(cells, endPos, startPos);
				break;
			}

			std::pair<int, int> downPos = { currentCellPos.first, currentCellPos.second + 1 };
			if (!CheckMove(cells, openList, endPos, downPos, currentCell, currentCellPos))
			{
				GetResult(cells, endPos, startPos);
				break;
			}
	}
}
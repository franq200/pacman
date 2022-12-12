#pragma once
#include <SFML/Graphics.hpp>

enum class State : std::uint8_t
{
	blocked = 0,
	free
};

class Cell : public sf::RectangleShape
{
public:
	Cell(int xPos, int yPos, State state);
	Cell(const Cell&) = default;
	Cell& operator=(const Cell&) = default;

	State GetState() const;
private:
	State m_state;
};
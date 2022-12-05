#pragma once
#include <SFML/Graphics.hpp>

enum class State
{
	blocked = 0,
	free
};

class Cell : public sf::RectangleShape
{
public:
	Cell(int xPos, int yPos, State state);

	State GetState() const;
private:
	State m_state;
};
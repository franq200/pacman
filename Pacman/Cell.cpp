#include "Cell.h"
#include "Helper.h"

Cell::Cell(sf::Vector2f pos, State state)
{
	setSize({ static_cast<float>(size::cellSize), static_cast<float>(size::cellSize) });
	setPosition(pos);
	if (state == State::free)
	{
		setFillColor(sf::Color::Green);
	}
	else
	{
		setFillColor(sf::Color::Red);
	}
}

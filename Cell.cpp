#include "Cell.h"
#include "Helper.h"

Cell::Cell(int xPos, int yPos, State state)
{
	setSize({ static_cast<float>(size::cellSize), static_cast<float>(size::cellSize) });
	setPosition({ static_cast<float>(xPos),static_cast<float>(yPos) });
	if (state == State::free)
	{
		setFillColor(sf::Color::Green);
	}
	else
	{
		setFillColor(sf::Color::Red);
	}
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(size::cellOutlineThickness);
}

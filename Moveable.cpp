#include "Moveable.h"
#include "Helper.h"

void Moveable::MakeMove(const Direction& direction)
{
	if (direction == Direction::up)
	{
		move(0.f, -1.f * (size::cellSize));
	}
	if (direction == Direction::left)
	{
		move(-1.f * size::cellSize, 0.f);
	}
	else if(direction == Direction::right)
	{
		move(static_cast<float>(size::cellSize), 0.f);
	}
	else if (direction == Direction::down)
	{
		move(0., static_cast<float>(size::cellSize));
	}
}

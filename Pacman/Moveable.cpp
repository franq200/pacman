#include "Moveable.h"
#include "Helper.h"

void Moveable::MakeMove(Direction direction)
{
	if (direction == Direction::up)
	{
		move(0, -(size::cellSize));
	}
	if (direction == Direction::left)
	{
		move(-(size::cellSize), 0);
	}
	else if(direction == Direction::right)
	{
		move(size::cellSize, 0);
	}
	else if (direction == Direction::down)
	{
		move(0, size::cellSize);
	}
}

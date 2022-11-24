#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
	up = 0,
	down,
	left,
	right
};

class Moveable : public sf::RectangleShape
{
public:
	void MakeMove(Direction direction);
private:
};
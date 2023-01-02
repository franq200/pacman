#pragma once
#include <SFML/Graphics.hpp>

enum class Direction : std::uint8_t
{
	up = 0,
	down,
	left,
	right
};

class Moveable : public sf::RectangleShape
{
public:
	void MakeMove(const Direction& direction);
private:
};
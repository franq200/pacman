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
	Cell(sf::Vector2f pos, State state);
private:
};
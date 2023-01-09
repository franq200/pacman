#pragma once
#include <SFML/Graphics.hpp>

class Bonus : public sf::RectangleShape
{
public:
	void virtual Init(sf::Vector2f pos) = 0;
private:
};
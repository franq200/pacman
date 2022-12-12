#pragma once
#include "Moveable.h"

class Ghost : public Moveable
{
public:
	void Init(const sf::Vector2f& ghostSpawn);
private:
};
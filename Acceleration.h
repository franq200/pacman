#pragma once
#include "Bonus.h"
#include "Pacman.h"

class Acceleration : public Bonus
{
public:
	void Init(sf::Vector2f pos) override;
	void MakeAction(Pacman &pacman) override;
private:
};
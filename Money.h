#pragma once
#include "Bonus.h"
#include "Pacman.h"

class Money : public Bonus
{
public:
	void Init(sf::Vector2f pos) override;
	void MakeAction(Pacman &pacman) override;
private:
	int m_score = 0;
};
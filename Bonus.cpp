#include "Bonus.h"

bool Bonus::IsAlive()
{
	m_isAlive &= m_expiredClock.getElapsedTime() <= sf::seconds(5.f);

	return m_isAlive;
}

void Bonus::TryMakeAction(Pacman &pacman)
{
	if (getPosition() == pacman.getPosition())
	{
		MakeAction(pacman);
		m_isAlive &= false;
	}
}

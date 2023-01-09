#include "Bonus.h"

bool Bonus::IsAlive() const
{
	return m_expiredClock.getElapsedTime() <= sf::seconds(5.f);
}

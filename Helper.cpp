#include "Helper.h"

namespace size
{
	int windowSize = 800;
	int cellsNum = 15;
	int cellSize = windowSize / cellsNum;
	float cellOutlineThickness = 3.f;
}

namespace speed
{
	int pacmanSpeed = 175;
	int ghostSpeed = 175;
}

namespace textures
{
	sf::Texture pacmanTexture;
	sf::Texture ghostTexture;
}
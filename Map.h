#pragma once
#include "Cell.h"
#include <string>
#include <vector>

class Map
{
public:
	void Init(std::string path);
private:
	void ReadMap();
	std::vector<std::vector<Cell>> m_map;
};
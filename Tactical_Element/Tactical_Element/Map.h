#pragma once

#include <map>
#include <vector>
#include <utility>
#include "Case.h"

class Map
{	
public:
	std::map<std::pair<int, int>, Case*> map;

public:
	Map(void);
	~Map(void);
};


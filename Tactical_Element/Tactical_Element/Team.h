#pragma once

#include <vector>
#include "Unit.h"

class Team
{
public:
	int initiative;
	std::vector<Unit*> units;

public:
	Team(void);
	~Team(void);
};


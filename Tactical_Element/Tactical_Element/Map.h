#pragma once

#include <map>
#include <vector>
#include <utility>
#include "Case.h"
#include "Spell.h"
#include "Settings.h"

class Map
{	
public:
	int w; int h;
	std::map<std::pair<int, int>, Case*> map;
	Case const *getCase(int x, int y);
	bool putEffectOnCase(Effect *, int x, int y);
	void createMap();
public:
	Map(void);
	~Map(void);
};


#pragma once

#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include "Case.h"
#include "Spell.h"
#include "Settings.h"

class Map
{	
public:
	int w; int h;
	std::map<std::pair<int , int>, bool> effectArea;
	std::map<std::pair<int, int>, Case*> map;
	Case *getCase(int x, int y);
	void showEffectArea(int x, int y, int lenght, bool center);
	bool putEffectOnCase(Effect *, int x, int y);
	void createMap();
public:
	Map(void);
	~Map(void);
};


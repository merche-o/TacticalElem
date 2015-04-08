#pragma once

#include <utility>
#include "Ressources.h"
#include "Map.h"
#include "Pos.h"


class Interface
{	
public:
	Map & map;
	Pos mousePos;
private:
	bool mousePositionChanged;
	
public:
	Interface(Map & m);
	~Interface(void);
	void run(void);
	void changeMousePosition(int x, int y);
private:
	const Case * getCaseByMouse(void);
};

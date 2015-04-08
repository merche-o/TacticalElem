#include "Interface.h"


#include <iostream>

Interface::Interface(Map & m) : map(m), mousePos(0, 0)
{
	mousePositionChanged = true;
}


Interface::~Interface(void)
{
}

void Interface::run(void)
{
	if (mousePositionChanged)
	{
		mousePositionChanged = false;
		getCaseByMouse();
	}
}

void Interface::changeMousePosition(int x, int y)
{
	mousePos.x = x;
	mousePos.y = y;
	mousePositionChanged = true;
}

const Case * Interface::getCaseByMouse()
{

	if (mousePos.x < Settings::MAP_WIDTH * Settings::CASE_SIZE && mousePos.y < Settings::MAP_HEIGHT * Settings::CASE_SIZE)
	{
		//std::cout << "mouse in map" << std::endl;
	}
	else
	{
	}
		//std::cout << "mouse NOOOT in map" << std::endl;
	return (map.getCase(0, 0));
}
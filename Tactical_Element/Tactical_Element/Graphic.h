#pragma once

#include <vector>
#include <string>
#include "Display.h"
#include "Map.h"
#include "Ressources.h"
#include "Interface.h"

class Graphic : public Display
{
private:
	Map & map;
	Ressources & ress;
	Interface & intface;

public:
	//faire une fonction display
	sf::RenderWindow & win;
	Graphic(sf::RenderWindow & w, Map & m, Ressources & r, Interface & i);
	~Graphic(void);

	void drawMap();
	void drawInterface();
};


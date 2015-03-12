#pragma once

#include <vector>
#include "Display.h"
#include "Map.h"
#include "Ressources.h"

class Graphic : public Display
{
private:
	Map & map;
	Ressources & ress;

public:
	//faire une fonction display
	sf::RenderWindow & win;
	Graphic(sf::RenderWindow & w, Map & m, Ressources & r);
	~Graphic(void);

	void drawMap();
};


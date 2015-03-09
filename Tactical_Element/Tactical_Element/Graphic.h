#pragma once

#include <vector>
#include "Display.h"
#include "Map.h"
#include "Ressources.h"

class Graphic : public Display
{
private:
	sf::RenderWindow & win;
	Map & map;
	Ressources & ress;

public:
	Graphic(sf::RenderWindow & w, Map & m, Ressources & r);
	~Graphic(void);

	void drawMap();
};


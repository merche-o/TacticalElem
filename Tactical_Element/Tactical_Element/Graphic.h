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
		sf::RenderWindow & win;
public:
	//faire une fonction display
	void display();
	Graphic(sf::RenderWindow & w, Map & m, Ressources & r);
	~Graphic(void);

	void drawMap(sf::Color a, Pos *mouse);
};


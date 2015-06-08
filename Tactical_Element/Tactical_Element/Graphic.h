#pragma once

#include <vector>
#include <string>
#include "Display.h"
#include "Map.h"
#include "Ressources.h"
#include "Team.h"
#include "TextEffect.h"

class Graphic : public Display
{
private:
	Map & map;
	Ressources & ress;
	std::vector<Team*> & teams;
	std::vector<TextEffect*> textEffect;

public:
	//faire une fonction display
	void display();
	sf::RenderWindow & win;
	Graphic(sf::RenderWindow & w, Map & m, Ressources & r, std::vector<Team*> & t);
	~Graphic(void);
	void drawMap(sf::Color a, Pos *mouse);
	void drawUnits();
	void addTextEffect(float x, float y, std::string & s, sf::Color color);
	void drawTextEffect();
};


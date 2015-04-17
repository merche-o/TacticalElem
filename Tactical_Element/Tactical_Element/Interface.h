#pragma once

#include <utility>
#include "Ressources.h"
#include "Map.h"
#include "Pos.h"
#include "Team.h"
#include "Event.h"
#include "InterfaceElement.h"
#include "InterfaceElementText.h"
#include "Display.h"
#include "Event.h"


class Interface : public Display
{
public:
	Map & map;
	std::vector<Team*> & teams;
	Unit * currentPlayerTurn; // CPT
	std::vector<InterfaceElement*> interfaceElements;
	InterfaceElement * hoverElement;
	InterfaceElement * clickedElement;
	Event & event;
	bool mouseReleased;
private:
	sf::Vector2i mousePosition;
	
public:
	Interface(sf::RenderWindow &, Map &, Event &, std::vector<Team*> &, Unit *);
	~Interface(void);
	void run(void);
	void draw(void);
};

void endTurn(void *);
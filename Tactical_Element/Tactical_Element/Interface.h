#pragma once

#include <utility>
#include "Ressources.h"
#include "Map.h"
#include "Pos.h"
#include "Team.h"
#include "Event.h"
#include "InterfaceElement.h"
#include "InterfaceElementText.h"
#include "InterfaceElementImage.h"
#include "Display.h"
#include "Event.h"
#include "Spell.h"


class Interface : public Display
{
public:
	Map					& map;
	std::vector<Team *>	& teams;
	Unit				* currentPlayerTurn; // CPT
	std::vector<InterfaceElement*>	interfaceElements;
	InterfaceElement	* hoverElement;
	InterfaceElement	* clickedElement;
	Spell				* spell;		
	Ressources			& ressources;
	Event				& event;
	bool				mouseReleased;

private:
	sf::Vector2i mousePosition;
	
public:
	Interface(sf::RenderWindow &, Map &, Event &, std::vector<Team*> &, Unit *, Ressources &);
	~Interface(void);
	void run(void);
	void draw(void);
};

void endTurn(void *);
void firstSpellClick(void *);
void secondSpellClick(void *);
void thirdSpellClick(void *);
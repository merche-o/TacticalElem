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
#include "Referee.h"


class Interface : public Display
{
public:
	Map					& map;
	std::vector<Team *>	& teams;
	Unit				** currentPlayerTurn; // CPT
	std::vector<InterfaceElement*>	interfaceElements;
	InterfaceElement	* hoverElement;
	InterfaceElement	* clickedElement;
	Spell				* spell;		
	Ressources			& ressources;
	Event				& event;
	Referee				** referee;
	bool				mouseReleased;

private:
	sf::Vector2i mousePosition;
	
public:
	Interface(sf::RenderWindow &, Map &, Event &, std::vector<Team*> &, Unit **, Ressources &, Referee **
		);
	~Interface(void);
	void run(void);
	void draw(void);
private:
	void pushBackElement(std::string, InterfaceElement *);
	void endTurn(void *);
	void firstSpellClick(void *);
	void secondSpellClick(void *);
	void thirdSpellClick(void *);
};

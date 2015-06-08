#pragma once

#include <utility>
#include <cmath>
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
	Case				* hoverCase;
	Unit				** currentPlayerTurn; // CPT
	std::vector<InterfaceElement*>	interfaceElements;
	InterfaceElement	* hoverElement;
	InterfaceElement	* clickedElement;
	Spell				* spell;		
	Ressources			& ressources;
	Event				& event;
	Referee				** referee;
	bool				mouseReleased;
	bool				mouseRight;

private:
	sf::Vector2i mousePosition;
	
public:
	Interface(sf::RenderWindow &, Map &, Event &, std::vector<Team*> &, Unit **, Ressources &, Referee **
		);
	~Interface(void);
	void run(void);
	void draw(void);

	void update_HoverCase(void);
	void update_HoverCase_Title(void);
	void update_HoverCase_Duration(void);
	void update_HoverCase_Life(int *);
	void update_HoverCase_Move(int *);
	void update_HoverCase_Action(int *);
	void update_HoverCase_Teleport(int *);
	void update_HoverCase_Displace(int *);
	void update_HoverCase_Wall(int *);

	void update_HoverPlayer(void);
	void update_HoverPlayer_Team(void);
	void update_HoverPlayer_LifePoints(void);
	void update_HoverPlayer_MovementsPoints(void);
	void update_HoverPlayer_ActionPoints(void);
	void update_HoverPlayer_SurchargeActionPoints(void);

	void update_CurrentPlayer(void);
	void update_CurrentPlayer_Team(void);
	void update_CurrentPlayer_Image(void);
	void update_CurrentPlayer_LifePoints(void);
	void update_CurrentPlayer_MovementsPoints(void);
	void update_CurrentPlayer_ActionPoints(void);
	void update_CurrentPlayer_SurchargeActionPoints(void);
	void firstSpellClick(void *);

private:
	void pushBackElement(std::string, InterfaceElement *);
	void drawFrame(int x, int y, int width, int height);
	void setHoverCase(void);
	void updateTimeLine(void);

	void endTurnClick(void *);
	void secondSpellClick(void *);
	void thirdSpellClick(void *);
	void mainMenuClick(void *);
};

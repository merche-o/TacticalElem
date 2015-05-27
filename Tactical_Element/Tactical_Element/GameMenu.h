#pragma once

#include "Display.h"
#include "Event.h"
#include "TextMenu.h"
#include "ImageMenu.h"
#include "Team.h"
#include "CharacterFactory.h"
#include "Ressources.h"
#include <utility>
#include <vector>
#include <map>
#include <string>
#include "ElementMenu.h"

class GameMenu : public Display
{
private:
	enum e_state
	{
		MAIN,
		TEAM_SELECTION,
		CREDITS,
		NONE
	};

public:
	sf::RenderWindow & win;
	Ressources & ress;
	
	std::vector<ElementMenu*> elemMenu;
	//std::map<std::pair<e_state, int>, TextMenu*> textMenu;
	//std::map<std::pair<e_state, int>, void(GameMenu:: *)()> actionMenu;
	//std::map<std::pair<e_state, int>, TextMenu*> keyTextMenu;
	//std::map<std::pair<e_state, int>, void(GameMenu:: *)()> actionImg;
	//std::map<std::pair<e_state, int>, ImageMenu*> keyImgMenu;
	//std::map<e_state, int> sizeKeyTextMenu;
	//std::map<e_state, int> sizeTextMenu;
	//std::map<e_state, int> sizeKeyImgMenu;
	e_state currentState;
	//std::vector<e_state> beforeState;
	int posMenu;
	ElementMenu* cursorPtr;
	bool isPushed;
	Event & event;
	std::vector<Team*> & teams;
	CharacterFactory & factoryUnit;
	bool & start;
	bool refresh;

public:
	GameMenu(sf::RenderWindow & w, Event & e, Ressources & r, std::vector<Team*> & t, CharacterFactory & FactoryUnit, bool & s);
	~GameMenu(void);
	
	void createMenu();
	void run();
	void displayCurrentMenu();
	void menuPlay();
	void menuSelection();
	void menuCredits();
	void menuMain();
	void menuQuit();
	void createElemOnlyOnce(ElementMenu* e);
	void selectUnit();
	void addUnitInTeam();
};


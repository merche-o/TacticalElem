#pragma once

#include "Display.h"
#include "Event.h"
#include "TextMenu.h"
#include <utility>
#include <vector>
#include <map>
#include <string>

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
	std::map<std::pair<e_state, int>, TextMenu*> textMenu;
	std::map<std::pair<e_state, int>, void(GameMenu:: *)()> actionMenu;
	std::map<std::pair<e_state, int>, TextMenu*> keyTextMenu;
	std::map<e_state, int> sizeKeyTextMenu;
	std::map<e_state, int> sizeTextMenu;
	e_state currentState;
	std::vector<e_state> beforeState;
	int posMenu;
	bool isPushed;
	Event & event;
	bool & start;
	bool refresh;

public:
	GameMenu(sf::RenderWindow & w, Event & e, bool & s);
	~GameMenu(void);
	
	void posInsideTheMenu();
	void run();
	void displayCurrentMenu();
	void menuPlay();
	void menuSelection();
	void menuCredits();
	void menuReturn();
	void addTextMenu(e_state state, TextMenu * text);
	void addKeyTextMenu(e_state state, TextMenu * text, void(GameMenu:: *p)());
};


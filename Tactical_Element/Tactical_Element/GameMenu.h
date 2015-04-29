#pragma once

#include "Display.h"
#include "Event.h"
#include "TextMenu.h"
#include "ImageMenu.h"
#include "Team.h"
#include "Ressources.h"
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
	std::map<std::pair<e_state, int>, void(GameMenu:: *)()> actionImg;
	std::map<std::pair<e_state, int>, ImageMenu*> keyImgMenu;
	std::map<e_state, int> sizeKeyTextMenu;
	std::map<e_state, int> sizeTextMenu;
	std::map<e_state, int> sizeKeyImgMenu;
	e_state currentState;
	std::vector<e_state> beforeState;
	int posMenu;
	bool isPushed;
	Event & event;
	Ressources & ress;
	std::vector<Team*> & teams;
	bool & start;
	bool refresh;

public:
	GameMenu(sf::RenderWindow & w, Event & e, Ressources & r, std::vector<Team*> & t, bool & s);
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
	void addKeyImgMenu(e_state state, ImageMenu * img, void(GameMenu:: *p)());
	int checkTextBounds();
};


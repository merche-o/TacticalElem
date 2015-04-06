#include "GameMenu.h"
#include <string>
#include <iostream>

GameMenu::GameMenu(sf::RenderWindow & w, Event & e, bool & s)
	: Display(w), win(w), event(e), start(s)
{
	refresh = true;
	isPushed = false;
	posMenu = -1;
	currentState = MAIN;
	beforeState.push_back(NONE);
	
	addTextMenu(MAIN, new TextMenu(350, 0, "Menu", 96, font, 250, 60, 60));
	addKeyTextMenu(MAIN, new TextMenu(200, 300, "Character Selection", 48, font), &GameMenu::menuSelection);
	addKeyTextMenu(MAIN, new TextMenu(200, 400, "Credits", 48, font), &GameMenu::menuCredits);
	addKeyTextMenu(MAIN, new TextMenu(200, 500, "Quit", 48, font), &GameMenu::menuReturn);

	addTextMenu(TEAM_SELECTION, new TextMenu(100, 0, "Character\n\tSelection", 96, font, 250, 60, 60));
	addKeyTextMenu(TEAM_SELECTION, new TextMenu(200, 400, "Play", 48, font), &GameMenu::menuPlay);
	addKeyTextMenu(TEAM_SELECTION, new TextMenu(200, 500, "Back", 48, font), &GameMenu::menuReturn);

	addTextMenu(CREDITS, new TextMenu(350, 0, "Credits", 96, font, 250, 60, 60));
	addTextMenu(CREDITS, new TextMenu(200, 200, "Nothing :\tOlivier", 48, font, 60, 200, 150));
	addTextMenu(CREDITS, new TextMenu(200, 300, "Nothing :\tMarc", 48, font, 60, 200, 150));
	addTextMenu(CREDITS, new TextMenu(200, 400, "Nothing :\tJoris", 48, font, 60, 200, 150));
	addTextMenu(CREDITS, new TextMenu(200, 500, "Nothing :\tAxel", 48, font, 60, 200, 150));
	addKeyTextMenu(CREDITS, new TextMenu(200,600, "Back", 48, font), &GameMenu::menuReturn);
}


GameMenu::~GameMenu(void)
{
}

void GameMenu::posInsideTheMenu()
{
	if (posMenu < 0)
		posMenu = sizeKeyTextMenu[currentState] - 1;
	else if (posMenu > sizeKeyTextMenu[currentState] - 1)
		posMenu = 0;
}

void GameMenu::run()
{
	if (refresh == true)
	{
		posMenu = checkTextBounds();
		if (isPushed == true && posMenu != -1)
		{
			if (posMenu != sizeKeyTextMenu[currentState] - 1) // If action != Return
				beforeState.push_back(currentState);
			(this->*(actionMenu[std::make_pair(currentState, posMenu)]))();
			posMenu = -1;
			isPushed = false;
			if (start == true)
			{
				refresh = true;
				return;
			}
		}
		//posInsideTheMenu();
		win.clear();
		displayCurrentMenu();
		win.display();

		refresh = false;
	}
	event.menuEvent(posMenu, isPushed, refresh);
}

void GameMenu::displayCurrentMenu()
{
	for (int i = 0; i < sizeTextMenu[currentState]; ++i)
	{
		loadText(textMenu[std::make_pair(currentState, i)]->x, 
				textMenu[std::make_pair(currentState, i)]->y, 
				font, 
				textMenu[std::make_pair(currentState, i)]->text, 
				textMenu[std::make_pair(currentState, i)]->size,
				textMenu[std::make_pair(currentState, i)]->color.r, 
				textMenu[std::make_pair(currentState, i)]->color.g, 
				textMenu[std::make_pair(currentState, i)]->color.b);
	}

	for (int i = 0; i < sizeKeyTextMenu[currentState]; ++i)
	{
		if (posMenu == i)
		{
			loadText(keyTextMenu[std::make_pair(currentState, i)]->x, 
					keyTextMenu[std::make_pair(currentState, i)]->y, 
					font, 
					keyTextMenu[std::make_pair(currentState, i)]->text, 
					keyTextMenu[std::make_pair(currentState, i)]->size, 
					250, 250, 60);
		}
		else
		{
			loadText(keyTextMenu[std::make_pair(currentState, i)]->x, 
					keyTextMenu[std::make_pair(currentState, i)]->y, 
					font, 
					keyTextMenu[std::make_pair(currentState, i)]->text, 
					keyTextMenu[std::make_pair(currentState, i)]->size, 
					250, 150, 60);
		}
	}
}

void GameMenu::menuPlay()
{
	start = true;
}

void GameMenu::menuSelection()
{
	currentState = TEAM_SELECTION;
}

void GameMenu::menuCredits()
{
	currentState = CREDITS;
}

void GameMenu::menuReturn()
{
	if (beforeState[beforeState.size() - 1] == NONE)
		win.close();
	else
	{
		currentState = beforeState[beforeState.size() - 1];
		beforeState.erase(beforeState.begin() + beforeState.size() - 1);
	}
}

void GameMenu::addTextMenu(e_state state, TextMenu * text)
{
	textMenu[std::make_pair(state, sizeTextMenu[state])] = text;
	sizeTextMenu[state]++;
}

void GameMenu::addKeyTextMenu(e_state state, TextMenu * text, void(GameMenu:: *p)())
{
	keyTextMenu[std::make_pair(state, sizeKeyTextMenu[state])] = text;
	actionMenu[std::make_pair(state, sizeKeyTextMenu[state])] = p;
	sizeKeyTextMenu[state]++;
}

int GameMenu::checkTextBounds()
{
	sf::FloatRect rect;
	for (unsigned int i = 0; i < sizeKeyTextMenu[currentState]; ++i)
	{
		rect = keyTextMenu[std::make_pair(currentState, i)]->menuText.getGlobalBounds();
		if (rect.contains((sf::Vector2f)event.mouse.getPosition(win)) == true)
		{
			return (i);
		}
	}
	return (-1);
}
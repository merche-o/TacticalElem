#include "GameMenu.h"
#include "Utils.h"
#include <string>
#include <iostream>

GameMenu::GameMenu(sf::RenderWindow & w, Event & e, Ressources & r, std::vector<Team*> & t, CharacterFactory & FactoryUnit, bool & s)
	: Display(w), win(w), event(e), ress(r), teams(t), factoryUnit(FactoryUnit), start(s)
{
}


GameMenu::~GameMenu(void)
{
}

void GameMenu::createMenu(void)
{
	refresh = true;
	isPushed = false;
	posMenu = -1;
	currentState = MAIN;
	cursorPtr = NULL;
	
	elemMenu.push_back(new TextMenu(win, 300, 100, ElementMenu::MAIN, NULL, "TACTICAL ELEMENT", 64, fontSpecial, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 300, ElementMenu::MAIN, &GameMenu::menuSelection, "Character Selection", 48, font, 250, 150, 60));
	elemMenu.push_back(new TextMenu(win, 200, 400, ElementMenu::MAIN, &GameMenu::menuCredits, "Credits", 48, font, 250, 150, 60));
	elemMenu.push_back(new TextMenu(win, 200, 500, ElementMenu::MAIN, &GameMenu::menuQuit, "Quit", 48, font, 250, 150, 60));

	elemMenu.push_back(new TextMenu(win, 100, 0, ElementMenu::TEAM_SELECTION, NULL, "CHARACTER\n\tSELECTION", 64, fontSpecial, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 100, 300, ElementMenu::TEAM_SELECTION, NULL, "Team 1", 48, font, 60, 150, 250));
	elemMenu.push_back(new TextMenu(win, 100, 350, ElementMenu::TEAM_SELECTION, NULL, "Team 2", 48, font, 60, 150, 250));
	elemMenu.push_back(new TextMenu(win, 800, 40, ElementMenu::TEAM_SELECTION, NULL, "Characters", 48, font, 222, 222, 222));
	elemMenu.push_back(new ImageMenu(win, 850, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createWaterUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 900, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createFireUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 950, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createLightningUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 1000, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createHeartUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 1050, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createBarbarianUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 1100, 100, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createMagicUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 850, 150, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createGhostUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 900, 150, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createKoreaUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 950, 150, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createPlantUnit(0, 0, ress)));
	elemMenu.push_back(new ImageMenu(win, 1000, 150, ElementMenu::TEAM_SELECTION, &GameMenu::selectUnit, factoryUnit.createYinYangUnit(0, 0, ress)));
	elemMenu.push_back(new TextMenu(win, 600, 600, ElementMenu::TEAM_SELECTION, NULL, "Play", 48, font, 150, 100, 50));
	elemMenu.push_back(new TextMenu(win, 600, 650, ElementMenu::TEAM_SELECTION, &GameMenu::menuMain, "Back", 48, font, 250, 150, 60));

	elemMenu.push_back(new TextMenu(win, 350, 0, ElementMenu::CREDITS, NULL, "Credits", 96, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 200, ElementMenu::CREDITS, NULL, "Map & Referee :\tOlivier", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 300, ElementMenu::CREDITS, NULL, "Graphic & Menu :\tMarc", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 400, ElementMenu::CREDITS, NULL, "Spell & Referee :\tJoris", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 500, ElementMenu::CREDITS, NULL, "Inteface :\tAxel", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 600, ElementMenu::CREDITS, &GameMenu::menuMain, "Back", 48, font, 250, 150, 60));


}

void GameMenu::run()
{
	if (refresh == true)
	{
		if (isPushed == true)
		{
			for (unsigned int i = 0; i < elemMenu.size(); ++i)
			{
				if (elemMenu[i]->p != NULL && elemMenu[i]->state == currentState)
				{
					if (elemMenu[i]->lighted == true)
					{
						elemMenu[i]->lighted = false;
						if (elemMenu[i]->getUnitSelected() != NULL)
							cursorPtr = elemMenu[i];
						(this->*elemMenu[i]->p)();
					}
				}
			}
			isPushed = false;
			if (start == true)
			{

				refresh = true;
				return;
			}
		}
		win.clear();
		displayCurrentMenu();
		win.display();

		refresh = false;
	}
	event.menuEvent(posMenu, isPushed, refresh);
}

void GameMenu::displayCurrentMenu()
{
	for (unsigned int i = 0; i < elemMenu.size(); ++i)
	{
		if (elemMenu[i]->state == currentState)
		{
			if (elemMenu[i]->p != NULL && elemMenu[i]->getBounds().contains((sf::Vector2f)event.mouse.getPosition(win)) == true)
				elemMenu[i]->lightDraw();
			else
				elemMenu[i]->draw();
		}
	}
	if (currentState == TEAM_SELECTION)
	{
		sf::RectangleShape rect;
		rect.setOutlineColor(sf::Color(255, 255, 255));
		rect.setFillColor(sf::Color(0, 0, 0, 0));
		rect.setOutlineThickness(3);
		rect.setPosition(790, 50);
		rect.setSize(sf::Vector2f(350, 140));
		win.draw(rect);
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

void GameMenu::menuMain()
{
	currentState = MAIN;
}

void GameMenu::menuQuit()
{
	win.close();
}

void GameMenu::createElemOnlyOnce(ElementMenu* e)
{
	for (int i = 0; i < elemMenu.size(); ++i)
	{
		if (elemMenu[i]->pos.x == e->pos.x && elemMenu[i]->pos.y == e->pos.y)
		{
			elemMenu.erase(elemMenu.begin() + i);
		}
	}
	elemMenu.push_back(e);
}

void GameMenu::selectUnit()
{
	createElemOnlyOnce(new TextMenu(win, 500, 200, ElementMenu::TEAM_SELECTION, NULL, "Unit Selected", 40, font, 222, 222, 222));
	createElemOnlyOnce(new ImageMenu(win, 700, 210, ElementMenu::TEAM_SELECTION, NULL, cursorPtr->getUnitSelected()));
	
	createElemOnlyOnce(new TextMenu(win, 550, 250, ElementMenu::TEAM_SELECTION, NULL, std::string("Life : " + IntToString(cursorPtr->getUnitSelected()->life)), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 550, 300, ElementMenu::TEAM_SELECTION, NULL, std::string("Initiative : " + IntToString(cursorPtr->getUnitSelected()->initiative)), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 800, 250, ElementMenu::TEAM_SELECTION, NULL, std::string("Action Points : " + IntToString(cursorPtr->getUnitSelected()->action_points)), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 800, 300, ElementMenu::TEAM_SELECTION, NULL, std::string("Movement Points : " + IntToString(cursorPtr->getUnitSelected()->move_points)), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 550, 350, ElementMenu::TEAM_SELECTION, NULL, std::string("Spell 1 : " + cursorPtr->getUnitSelected()->spells[0]->description), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 550, 400, ElementMenu::TEAM_SELECTION, NULL, std::string("Spell 2 : " + cursorPtr->getUnitSelected()->spells[1]->description), 32, font, 200, 200, 200));
	createElemOnlyOnce(new TextMenu(win, 550, 450, ElementMenu::TEAM_SELECTION, NULL, std::string("Spell 3 : " + cursorPtr->getUnitSelected()->spells[2]->description), 32, font, 200, 200, 200));

	createElemOnlyOnce(new TextMenu(win, 700, 500, ElementMenu::TEAM_SELECTION, &GameMenu::addUnitInTeam, "Select", 48, font, 250, 150, 60));
}

void GameMenu::addUnitInTeam()
{
	if (teams[0]->units.size() <= teams[1]->units.size() && teams[0]->units.size() < 3)
	{
		teams[0]->units.push_back(factoryUnit.createUnitWithType(cursorPtr->getUnitSelected()->type, 0, teams[0]->units.size(), ress));
		elemMenu.push_back(new ImageMenu(win, 200 + (teams[0]->units.size() * 64), 310, ElementMenu::TEAM_SELECTION, NULL, teams[0]->units[teams[0]->units.size() - 1]));
	}
	else if (teams[0]->units.size() > teams[1]->units.size())
	{
		teams[1]->units.push_back(factoryUnit.createUnitWithType(cursorPtr->getUnitSelected()->type, 1, teams[1]->units.size(), ress));
		elemMenu.push_back(new ImageMenu(win, 200 + (teams[1]->units.size() * 64), 360, ElementMenu::TEAM_SELECTION, NULL, teams[1]->units[teams[1]->units.size() - 1]));
		
		// Bouton Play en key
		if (teams[1]->units.size() == 3)
		{
			for (int i = 0; i < elemMenu.size(); ++i)
			{
				if (elemMenu[i]->state == TEAM_SELECTION && elemMenu[i]->getStringText().compare(std::string("Play")) == 0)
				{
					elemMenu.erase(elemMenu.begin() + i);
					elemMenu.push_back(new TextMenu(win, 600, 600, ElementMenu::TEAM_SELECTION, &GameMenu::menuPlay, "Play", 48, font, 250, 150, 60));
				}
			}

			for (int i = 0; i < teams.size(); ++i)
			{
				for (int j = 0; j < teams[i]->units.size(); ++j)
				{
					teams[i]->units[j]->pos.x = 2 + (j * 3);
					teams[i]->units[j]->pos.y = 1 + (i * 9);
				}
			}
		}
	}
}
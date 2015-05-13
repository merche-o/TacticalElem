#include "GameMenu.h"
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
	//beforeState.push_back(NONE);
	cursorPtr = NULL;
	
	elemMenu.push_back(new TextMenu(win, 350, 0, ElementMenu::MAIN, NULL, "Menu", 96, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 300, ElementMenu::MAIN, &GameMenu::menuSelection, "Character Selection", 48, font, 250, 150, 60));
	elemMenu.push_back(new TextMenu(win, 200, 400, ElementMenu::MAIN, &GameMenu::menuCredits, "Credits", 48, font, 250, 150, 60));
	elemMenu.push_back(new TextMenu(win, 200, 500, ElementMenu::MAIN, &GameMenu::menuQuit, "Quit", 48, font, 250, 150, 60));
	//addTextMenu(MAIN, new TextMenu(350, 0, "Menu", 96, font, 250, 60, 60));
	//addKeyTextMenu(MAIN, new TextMenu(200, 300, "Character Selection", 48, font), &GameMenu::menuSelection);
	//addKeyTextMenu(MAIN, new TextMenu(200, 400, "Credits", 48, font), &GameMenu::menuCredits);
	//addKeyTextMenu(MAIN, new TextMenu(200, 500, "Quit", 48, font), &GameMenu::menuReturn);
	
	elemMenu.push_back(new TextMenu(win, 100, 0, ElementMenu::TEAM_SELECTION, NULL, "Character\n\tSelection", 96, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 100, 300, ElementMenu::TEAM_SELECTION, NULL, "Team 1", 48, font, 60, 60, 250));
	elemMenu.push_back(new TextMenu(win, 100, 350, ElementMenu::TEAM_SELECTION, NULL, "Team 2", 48, font, 60, 60, 250));
	elemMenu.push_back(new TextMenu(win, 800, 40, ElementMenu::TEAM_SELECTION, NULL, "Characters", 48, font, 222, 222, 222));
	ress.unitTexture[Unit::WATER];
	elemMenu.push_back(new ImageMenu(win, 850, 100, ElementMenu::TEAM_SELECTION, &GameMenu::addUnitInTeam, factoryUnit.createUnit(ress, Unit::WATER)));
	elemMenu.push_back(new ImageMenu(win, 900, 100, ElementMenu::TEAM_SELECTION, &GameMenu::addUnitInTeam, factoryUnit.createUnit(ress, Unit::FIRE)));
	elemMenu.push_back(new ImageMenu(win, 950, 100, ElementMenu::TEAM_SELECTION, &GameMenu::addUnitInTeam, factoryUnit.createUnit(ress, Unit::LIGHTNING)));
	elemMenu.push_back(new ImageMenu(win, 1000, 100, ElementMenu::TEAM_SELECTION, &GameMenu::addUnitInTeam, factoryUnit.createUnit(ress, Unit::HEART)));
	//elemMenu.push_back(new TextMenu(win, 600, 600, ElementMenu::TEAM_SELECTION, &GameMenu::menuPlay, "Play", 48, font, 250, 150, 60));
	elemMenu.push_back(new TextMenu(win, 600, 600, ElementMenu::TEAM_SELECTION, NULL, "Play", 48, font, 150, 100, 50));
	elemMenu.push_back(new TextMenu(win, 600, 650, ElementMenu::TEAM_SELECTION, &GameMenu::menuMain, "Back", 48, font, 250, 150, 60));
	//// Faire images et texts en heritage sur interface
	//// Remplacer la texture par une Unit cree via la factory
	//addTextMenu(TEAM_SELECTION, new TextMenu(100, 0, "Character\n\tSelection", 96, font, 250, 60, 60));
	//addKeyCharacterMenu(TEAM_SELECTION, factoryUnit.createUnit(Unit::WATER), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(850, 100, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(900, 100, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(950, 100, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(1000, 100, ress.texture["test"]), &GameMenu::addUnitInTeam); 
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(800, 150, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(850, 150, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(900, 150, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(950, 150, ress.texture["test"]), &GameMenu::addUnitInTeam);
	////addKeyCharacterMenu(TEAM_SELECTION, new ImageMenu(1000, 150, ress.texture["test"]), &GameMenu::addUnitInTeam);
	//addTextMenu(TEAM_SELECTION, new TextMenu(100, 300, "Team 1", 48, font, 250, 150, 60));
	//addTextMenu(TEAM_SELECTION, new TextMenu(100, 350, "Team 2", 48, font, 250, 150, 60));
	//addKeyTextMenu(TEAM_SELECTION, new TextMenu(600, 600, "Play", 48, font), &GameMenu::menuPlay);
	//addKeyTextMenu(TEAM_SELECTION, new TextMenu(600, 650, "Back", 48, font), &GameMenu::menuReturn);

	elemMenu.push_back(new TextMenu(win, 350, 0, ElementMenu::CREDITS, NULL, "Credits", 96, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 200, ElementMenu::CREDITS, NULL, "Nothing :\tOlivier", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 300, ElementMenu::CREDITS, NULL, "Nothing :\tMarc", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 400, ElementMenu::CREDITS, NULL, "Nothing :\tJoris", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 500, ElementMenu::CREDITS, NULL, "Nothing :\tAxel", 48, font, 250, 60, 60));
	elemMenu.push_back(new TextMenu(win, 200, 600, ElementMenu::CREDITS, &GameMenu::menuMain, "Back", 48, font, 250, 150, 60));
	//addTextMenu(CREDITS, new TextMenu(350, 0, "Credits", 96, font, 250, 60, 60));
	//addTextMenu(CREDITS, new TextMenu(200, 200, "Nothing :\tOlivier", 48, font, 60, 200, 150));
	//addTextMenu(CREDITS, new TextMenu(200, 300, "Nothing :\tMarc", 48, font, 60, 200, 150));
	//addTextMenu(CREDITS, new TextMenu(200, 400, "Nothing :\tJoris", 48, font, 60, 200, 150));
	//addTextMenu(CREDITS, new TextMenu(200, 500, "Nothing :\tAxel", 48, font, 60, 200, 150));
	//addKeyTextMenu(CREDITS, new TextMenu(200, 600, "Back", 48, font), &GameMenu::menuReturn);


}
//void GameMenu::posInsideTheMenu()
//{
//	if (posMenu < 0)
//		posMenu = sizeKeyTextMenu[currentState] - 1;
//	else if (posMenu > sizeKeyTextMenu[currentState] - 1)
//		posMenu = 0;
//}

void GameMenu::run()
{
	if (refresh == true)
	{
		//posMenu = checkTextBounds();
		if (isPushed == true)
		{
			//if (cursorPtr != NULL)
			//if (posMenu != -1)
			//{
				for (unsigned int i = 0; i < elemMenu.size(); ++i)
				{
					if (elemMenu[i]->p != NULL && elemMenu[i]->state == currentState)
					{
						if (elemMenu[i]->lighted == true)
						{
							elemMenu[i]->lighted = false;
							cursorPtr = elemMenu[i];
							(this->*elemMenu[i]->p)();
						}
					}
				}
				//if (posMenu != sizeKeyTextMenu[currentState] - 1) // If action != Return
				//	beforeState.push_back(currentState);
				//(this->*(actionMenu[std::make_pair(currentState, posMenu)]))();
				//posMenu = -1;
				isPushed = false;
				if (start == true)
				{
					refresh = true;
					return;
				}
			//}
			//else
			//{
			//	// if () // Condition : savoir si la souris est sur une image
			//	// (this->*(actionImg[std::make_pair(currentState, posMenu)]))();
			//	isPushed = false;
			//}
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
	//for (int i = 0; i < sizeTextMenu[currentState]; ++i)
	//{
	//	loadText(textMenu[std::make_pair(currentState, i)]->x, 
	//			textMenu[std::make_pair(currentState, i)]->y, 
	//			font, 
	//			textMenu[std::make_pair(currentState, i)]->text, 
	//			textMenu[std::make_pair(currentState, i)]->size,
	//			textMenu[std::make_pair(currentState, i)]->color.r, 
	//			textMenu[std::make_pair(currentState, i)]->color.g, 
	//			textMenu[std::make_pair(currentState, i)]->color.b);
	//}

	//for (int i = 0; i < sizeKeyTextMenu[currentState]; ++i)
	//{
	//	if (posMenu == i)
	//	{
	//		loadText(keyTextMenu[std::make_pair(currentState, i)]->x, 
	//				keyTextMenu[std::make_pair(currentState, i)]->y, 
	//				font, 
	//				keyTextMenu[std::make_pair(currentState, i)]->text, 
	//				keyTextMenu[std::make_pair(currentState, i)]->size, 
	//				250, 250, 60);
	//	}
	//	else
	//	{
	//		loadText(keyTextMenu[std::make_pair(currentState, i)]->x, 
	//				keyTextMenu[std::make_pair(currentState, i)]->y, 
	//				font, 
	//				keyTextMenu[std::make_pair(currentState, i)]->text, 
	//				keyTextMenu[std::make_pair(currentState, i)]->size, 
	//				250, 150, 60);
	//	}
	//}

	//for (int i = 0; i < sizeKeyImgMenu[currentState]; ++i)
	//{
	//	loadImage(keyImgMenu[std::make_pair(currentState, i)]->x,
	//				keyImgMenu[std::make_pair(currentState, i)]->y,
	//				keyImgMenu[std::make_pair(currentState, i)]->unit->texture);
	//}

	//if (currentState == TEAM_SELECTION)
	//	for (int i = 0; i < teams.size(); ++i)
	//	{
	//		for (int j = 0; j < teams[i]->units.size(); ++j)
	//		{
	//			loadImage(0, 0, ress.texture["test"]); // CHANGER
	//			//loadImage(0, 0, teams[i]->units[j]->texture); // CHANGER
	//		}
	//	}
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
//
//void GameMenu::menuReturn()
//{
//	if (beforeState[beforeState.size() - 1] == NONE)
//		win.close();
//	else
//	{
//		currentState = beforeState[beforeState.size() - 1];
//		beforeState.erase(beforeState.begin() + beforeState.size() - 1);
//	}
//}

//void GameMenu::addTextMenu(e_state state, TextMenu * text)
//{
//	//textMenu[std::make_pair(state, sizeTextMenu[state])] = text;
//	//sizeTextMenu[state]++;
//}
//
//void GameMenu::addKeyTextMenu(e_state state, TextMenu * text, void(GameMenu:: *p)())
//{
//	//keyTextMenu[std::make_pair(state, sizeKeyTextMenu[state])] = text;
//	//actionMenu[std::make_pair(state, sizeKeyTextMenu[state])] = p;
//	//sizeKeyTextMenu[state]++;
//}
//
//void GameMenu::addKeyCharacterMenu(e_state state, Unit * u, void(GameMenu:: *p)(Unit *u))
//{
//	//keyImgMenu[std::make_pair(state, sizeKeyImgMenu[state])] = img;
//	//actionImg[std::make_pair(state, sizeKeyImgMenu[state])] = p;
//	//sizeKeyImgMenu[state]++;
//
//	//// mettre O sur image
//	//addKeyTextMenu(state, new TextMenu(img->x + 6, img->y - 38, "o", 72, font), p);
//
//	//keyTextMenu[std::make_pair(state, sizeKeyTextMenu[state])] = new TextMenu(img->x + 6, img->y - 38, "o", 72, font);
//	//sizeKeyTextMenu[state]++;
//}

//int GameMenu::checkTextBounds()
//{
//	sf::FloatRect rect;
//
//	for (unsigned int i = 0; i < elemMenu.size(); ++i)
//	{
//		if (elemMenu[i]->state == currentState && elemMenu[i]->p != NULL)
//		{
//			rect = elemMenu[i]->getBounds();
//			if (rect.contains((sf::Vector2f)event.mouse.getPosition(win)) == true)
//			{
//				return (i);
//			}
//		}
//	}
//	return (-1);
//}

void GameMenu::addUnitInTeam()
{
	if (teams[0]->units.size() <= teams[1]->units.size() && teams[0]->units.size() < 3)
	{
		teams[0]->units.push_back(cursorPtr->getUnitSelected()->createUnitWithType(cursorPtr->getUnitSelected(), 0, teams[0]->units.size() -1 ));
		elemMenu.push_back(new ImageMenu(win, 200 + (teams[0]->units.size() * 64), 310, ElementMenu::TEAM_SELECTION, NULL, teams[0]->units[teams[0]->units.size() - 1]));
	}
	else if (teams[0]->units.size() > teams[1]->units.size())
	{
		teams[1]->units.push_back(cursorPtr->getUnitSelected()->createUnitWithType(cursorPtr->getUnitSelected(), 1, teams[1]->units.size() - 1));
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
						std::cout << "lol team = " << i  << " player " << j <<  "pos x" << teams[i]->units[j]->pos.x  << " pos y "  << teams[i]->units[j]->pos.y << std::endl;
				}
			}
		}
	}
}
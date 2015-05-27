#include "Interface.h"

#include <iostream>

Interface::Interface(sf::RenderWindow & _window, Map & _map, Event & _event, std::vector<Team*> & _teams, Unit ** _currentPlayerTurn, Ressources & _ressources, Referee ** _referee)
	: Display(_window), map(_map), event(_event), teams(_teams), currentPlayerTurn(_currentPlayerTurn), ressources(_ressources), referee(_referee), hoverElement(NULL), clickedElement(NULL), mouseReleased(true), hoverCase(NULL)
{
	//interfaceElements.push_back(new InterfaceElementText(& endTurn, Pos(10, 10), 20, std::string("texte"), sf::Color(255, 255, 255), interfaceFont));
	//interfaceElements.push_back(new InterfaceElementImage(& endTurn, Pos(10, 10), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	pushBackElement("skill_1", new InterfaceElementImage(&Interface::firstSpellClick, Pos(50, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	pushBackElement("skill_2", new InterfaceElementImage(&Interface::secondSpellClick, Pos(150, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_2"], ressources.texture["skill_2_pressed"]));
	pushBackElement("skill_3", new InterfaceElementImage(&Interface::thirdSpellClick, Pos(250, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_3"], ressources.texture["skill_3_pressed"]));
	pushBackElement("skill_description", new InterfaceElementText(NULL, Pos(100, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 100), 20, std::string("skill description Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("end_turn", new InterfaceElementText(&Interface::endTurnClick, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH - 105, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), 20, std::string("End Turn"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("CurrentPlayer_Team", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 10), 20, std::string("Team number Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_Image", new InterfaceElementImage(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 30), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("CurrentPlayer_LifePoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 100), 20, std::string("Life Ppints Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_MovementPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 130), 20, std::string("Movements points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_ActionPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 160), 20, std::string("Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));
}


Interface::~Interface(void)
{
}

void Interface::run(void)
{
	sf::Vector2i	newMousePosition;
	bool			mouseClickStart;
	bool			mouseClickEnd;

	newMousePosition = event.mouse.getPosition(win);
	mouseClickStart = false;
	mouseClickEnd = false;
	setHoverCase();
	if (mouseReleased && event.mouse.isButtonPressed(sf::Mouse::Button::Left))
	{
		mouseReleased = false;
		mouseClickStart = true;
	}
	else if (!mouseReleased && !event.mouse.isButtonPressed(sf::Mouse::Button::Left))
	{
		mouseReleased = true;
		mouseClickEnd = true;
	}
	if (newMousePosition != mousePosition || mouseClickStart)
	{
		mousePosition = newMousePosition;
		if (hoverElement != NULL && !hoverElement->mouseIntersection(mousePosition))
		{
			hoverElement->isHover = false;
			hoverElement = NULL;
		}
		for (int i = 0; i < interfaceElements.size(); ++i)
		{
			if (interfaceElements[i]->mouseIntersection(mousePosition))
			{
				if (!interfaceElements[i]->isHover)
				{
					hoverElement = interfaceElements[i];
					hoverElement->isHover = true;
					//hoverElement->isUpdated = true;
				}
				if (mouseClickStart)
				{
					clickedElement = interfaceElements[i];
					clickedElement->isClicked = true;
					//clickedElement->isUpdated = true;
				}
				break;
			}
		}
	}
	if (mouseClickEnd && clickedElement != NULL)
	{
		if (clickedElement->mouseIntersection(mousePosition) && clickedElement->isClickable)
		{
			(this->*clickedElement->mouseClickAction)(NULL);
		}
		clickedElement->isClicked = false;
		//clickedElement->isUpdated = true;
		clickedElement = NULL;
	}
}


void Interface::draw(void)
{
	drawFrame(0, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT, Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH - 5, Settings::INTERFACE_BOTTOM_HEIGHT);
	drawFrame(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, 0, Settings::INTERFACE_RIGHT_WIDTH, Settings::HEIGHT);
	
	for (int i = 0; i < interfaceElements.size(); ++i)
	{
		//if (interfaceElements[i]->isUpdated)
			interfaceElements[i]->draw(this);
	}
}

void Interface::pushBackElement(std::string id, InterfaceElement * interfaceElement)
{
	interfaceElements.push_back(interfaceElement);
	ressources.stringInterface[id] = interfaceElement;
}

void Interface::setHoverCase(void)
{
	Case * newHoverCase;

	if (map.map[std::make_pair(event.mouse.getPosition(win).x / Settings::CASE_SIZE, event.mouse.getPosition(win).y / Settings::CASE_SIZE)])
		newHoverCase = map.map[std::pair<int, int>((int)(event.mouse.getPosition(win).x /( Settings::CASE_SIZE + 2)), (int)(event.mouse.getPosition(win).y / (Settings::CASE_SIZE)))];
	else
		newHoverCase = NULL;
	if (newHoverCase != hoverCase)
	{
		hoverCase = newHoverCase;
	}
}

void Interface::drawFrame(int posX, int posY, int width, int height)
{
	int margin = 2;
	sf::RectangleShape r;
	r.setFillColor(sf::Color(85, 85, 85, 255));
	r.setPosition(posX + margin, posY + margin);
	r.setSize(sf::Vector2f(width - margin * 2, height - margin * 2));
	win.draw(r);

	if ((width < ressources.texture["corner_TL"].getSize().x * 2 + ressources.texture["border_TB"].getSize().x) || (height < ressources.texture["corner_TL"].getSize().x * 2 + ressources.texture["border_TB"].getSize().x))
		return;
	loadImage(posX, posY, ressources.texture["corner_TL"]);
	for (int x = posX + ressources.texture["corner_TL"].getSize().x; x < posX + width - ressources.texture["corner_TR"].getSize().x; ++x)
	{
		loadImage(x, posY, ressources.texture["border_TB"]);
	}
	loadImage(posX + width - ressources.texture["corner_TR"].getSize().x, posY, ressources.texture["corner_TR"]);
	for (int y = posY + ressources.texture["corner_TR"].getSize().y; y < posY + height - ressources.texture["corner_BR"].getSize().y; ++y)
	{
		loadImage(posX + width - ressources.texture["border_LR"].getSize().x, y, ressources.texture["border_LR"]);
	}
	loadImage(posX + width - ressources.texture["corner_BR"].getSize().x, posY + height - ressources.texture["corner_BR"].getSize().y, ressources.texture["corner_BR"]);
	for (int x = posX + width - ressources.texture["corner_BR"].getSize().x - ressources.texture["border_TB"].getSize().x; x > posX + ressources.texture["corner_BL"].getSize().x - 1; --x)
	{
		loadImage(x, posY + height - ressources.texture["border_TB"].getSize().y, ressources.texture["border_TB"]);
	}
	loadImage(posX, posY + height - ressources.texture["corner_BL"].getSize().y, ressources.texture["corner_BL"]);
	for (int y = posY + height - ressources.texture["corner_BL"].getSize().y - ressources.texture["border_LR"].getSize().y; y > posY + ressources.texture["corner_TL"].getSize().y - 1; --y)
	{
		loadImage(posX, y, ressources.texture["border_LR"]);
	}
}

//
//Fonctions associées a un bouton
//

void Interface::endTurnClick(void *)
{
	//std::cout << "endTurn" << std::endl;
	(*referee)->changeCPT();
	firstSpellClick(NULL);
	update_CurrentPlayer();
}

void Interface::firstSpellClick(void *)
{
	((InterfaceElementText *) ressources.stringInterface["skill_description"])->updateString((*currentPlayerTurn)->spells[0]->description);
	spell = (*currentPlayerTurn)->spells[0];
}

void Interface::secondSpellClick(void *)
{
	((InterfaceElementText *) ressources.stringInterface["skill_description"])->updateString((*currentPlayerTurn)->spells[1]->description);
	spell = (*currentPlayerTurn)->spells[1];
}

void Interface::thirdSpellClick(void *)
{
	((InterfaceElementText *) ressources.stringInterface["skill_description"])->updateString((*currentPlayerTurn)->spells[2]->description);
	spell = (*currentPlayerTurn)->spells[2];
}

void Interface::mainMenuClick(void *)
{
}

//
// Fonctions de mise à jour des données de l'interface
//

void Interface::update_CurrentPlayer(void)
{
	update_CurrentPlayer_Team();
	update_CurrentPlayer_Image();
	update_CurrentPlayer_LifePoints();
	update_CurrentPlayer_MovementsPoints();
	update_CurrentPlayer_ActionPoints();
}

void Interface::update_CurrentPlayer_Team(void)
{
	std::string newString;
	newString = "Team : " +  std::to_string((long double)(*currentPlayerTurn)->team_number);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_Team"])->updateString(newString);
}

void Interface::update_CurrentPlayer_Image(void)
{
	((InterfaceElementImage *) ressources.stringInterface["CurrentPlayer_Image"])->updateTexture(ressources.unitTexture[(*currentPlayerTurn)->type]);
}

void Interface::update_CurrentPlayer_LifePoints(void)
{
	std::string newString;
	newString = "Life : " +  std::to_string((long double)(*currentPlayerTurn)->life);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_LifePoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_MovementsPoints(void)
{
	std::string newString;
	newString = "Movements : " +  std::to_string((long double)(*currentPlayerTurn)->life);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_MovementPoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_ActionPoints(void)
{
	std::string newString;
	newString = "Actions : " +  std::to_string((long double)(*currentPlayerTurn)->life);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_ActionPoints"])->updateString(newString);
}
#include "Interface.h"

#include <iostream>

Interface::Interface(sf::RenderWindow & _window, Map & _map, Event & _event, std::vector<Team*> & _teams, Unit ** _currentPlayerTurn, Ressources & _ressources, Referee ** _referee, std::vector<Unit*> & _timeLine)
	: Display(_window), map(_map), event(_event), teams(_teams), currentPlayerTurn(_currentPlayerTurn), ressources(_ressources), referee(_referee), hoverElement(NULL), clickedElement(NULL), mouseReleased(true), hoverCase(NULL), timeLine(_timeLine)
{
	//interfaceElements.push_back(new InterfaceElementText(& endTurn, Pos(10, 10), 20, std::string("texte"), sf::Color(255, 255, 255), interfaceFont));
	//interfaceElements.push_back(new InterfaceElementImage(& endTurn, Pos(10, 10), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	pushBackElement("Skill_1", new InterfaceElementImage(&Interface::firstSpellClick, Pos(Settings::INTERFACE_SPELLS[0] + 50, Settings::INTERFACE_SPELLS[1]), & ressources.texture["skill_1"], & ressources.texture["skill_1_pressed"]));
	pushBackElement("Skill_2", new InterfaceElementImage(&Interface::secondSpellClick, Pos(Settings::INTERFACE_SPELLS[0] + 180, Settings::INTERFACE_SPELLS[1]), & ressources.texture["skill_2"], & ressources.texture["skill_2_pressed"]));
	pushBackElement("Skill_3", new InterfaceElementImage(&Interface::thirdSpellClick, Pos(Settings::INTERFACE_SPELLS[0] + 310, Settings::INTERFACE_SPELLS[1]), & ressources.texture["skill_3"], & ressources.texture["skill_3_pressed"]));
	pushBackElement("Skill_Cost", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0], Settings::INTERFACE_SPELLS[1] + 70), 18, std::string("skill Cost Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("Skill_Description", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0] + 120, Settings::INTERFACE_SPELLS[1] + 70), 20, std::string("skill description Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("Skill_Duration", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0] + 10, Settings::INTERFACE_SPELLS[1] + 110), 18, std::string("HoverCase_Duration default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("Skill_Effect_1", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0] + 150, Settings::INTERFACE_SPELLS[1] + 110), 18, std::string("HoverCase_Effect_1 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("Skill_Effect_2", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0] + 10, Settings::INTERFACE_SPELLS[1] + 150), 18, std::string("HoverCase_Effect_2 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("Skill_Effect_3", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_SPELLS[0] + 150, Settings::INTERFACE_SPELLS[1] + 150), 18, std::string("HoverCase_Effect_3 default value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("CurrentPlayer_Team", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_CURRENT_PLAYER[0] + 65, Settings::INTERFACE_CURRENT_PLAYER[1] + 5), 18, std::string("Team number Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_Image", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_CURRENT_PLAYER[0] + 130, Settings::INTERFACE_CURRENT_PLAYER[1]), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("CurrentPlayer_LifePoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_CURRENT_PLAYER[0] + 20, Settings::INTERFACE_CURRENT_PLAYER[1] + 70), 18, std::string("Life Points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_MovementPoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_CURRENT_PLAYER[0] + 20, Settings::INTERFACE_CURRENT_PLAYER[1] + 105), 18, std::string("Movements points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_ActionPoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_CURRENT_PLAYER[0] + 20, Settings::INTERFACE_CURRENT_PLAYER[1] + 140), 18, std::string("Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("HoverPlayer_Team", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_PLAYER[0] + 140, Settings::INTERFACE_HOVER_PLAYER[1]), 18, std::string("Team number Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_Image", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_HOVER_PLAYER[0] + 150, Settings::INTERFACE_HOVER_PLAYER[1] + 30), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("HoverPlayer_LifePoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_PLAYER[0] + 40, Settings::INTERFACE_HOVER_PLAYER[1]), 18, std::string("Life Points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_MovementPoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_PLAYER[0] + 40, Settings::INTERFACE_HOVER_PLAYER[1] + 40), 18, std::string("Movements points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_ActionPoints", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_PLAYER[0] + 40, Settings::INTERFACE_HOVER_PLAYER[1] + 80), 18, std::string("Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("HoverCase_Title", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_CASE[0] + 20, Settings::INTERFACE_HOVER_CASE[1]), 18, std::string("HoverCase_Title default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Duration", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_CASE[0], Settings::INTERFACE_HOVER_CASE[1] + 45), 18, std::string("HoverCase_Duration default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_1", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_CASE[0], Settings::INTERFACE_HOVER_CASE[1] + 75), 18, std::string("HoverCase_Effect_1 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_2", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_CASE[0], Settings::INTERFACE_HOVER_CASE[1] + 105), 18, std::string("HoverCase_Effect_2 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_3", new InterfaceElementText(NULL, Pos(Settings::INTERFACE_HOVER_CASE[0], Settings::INTERFACE_HOVER_CASE[1] + 135), 18, std::string("HoverCase_Effect_3 default value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("end_turn", new InterfaceElementText(&Interface::endTurnClick, Pos(Settings::INTERFACE_TIMELINE[0] + 185, Settings::INTERFACE_TIMELINE[1] - 5), 22, std::string("End Turn"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("PlayerTimeLine_1", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 10, Settings::INTERFACE_TIMELINE[1] + 55), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("PlayerTimeLine_2", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 40, Settings::INTERFACE_TIMELINE[1] + 115), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("PlayerTimeLine_3", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 110, Settings::INTERFACE_TIMELINE[1] + 55), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("PlayerTimeLine_4", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 140, Settings::INTERFACE_TIMELINE[1] + 115), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("PlayerTimeLine_5", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 210, Settings::INTERFACE_TIMELINE[1] + 55), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	pushBackElement("PlayerTimeLine_6", new InterfaceElementImage(NULL, Pos(Settings::INTERFACE_TIMELINE[0] + 240, Settings::INTERFACE_TIMELINE[1] + 115), & ressources.unitTexture[Unit::GHOST], & ressources.unitTexture[Unit::GHOST]));
	// faire fonction qui affiche un out of mana quand un clique sur un sort non lancable

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
	//drawFrame(0, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT, Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH - 5, Settings::INTERFACE_BOTTOM_HEIGHT);
	//drawFrame(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, 0, Settings::INTERFACE_RIGHT_WIDTH, Settings::HEIGHT);
	drawFrame(Settings::INTERFACE_HOVER_PLAYER[0] - 30, Settings::INTERFACE_HOVER_PLAYER[1] - 30, 290, 175);
	drawFrame(Settings::INTERFACE_HOVER_CASE[0] - 30, Settings::INTERFACE_HOVER_CASE[1] - 30, 290, 220);
	drawFrame(Settings::INTERFACE_CURRENT_PLAYER[0] - 30, Settings::INTERFACE_CURRENT_PLAYER[1] - 30, 290, 235);
	drawFrame(Settings::INTERFACE_SPELLS[0] - 30, Settings::INTERFACE_SPELLS[1] - 30, 500, 215);
	drawFrame(Settings::INTERFACE_TIMELINE[0] - 30, Settings::INTERFACE_TIMELINE[1] - 30, 350, 215);
	updateTimeLine();
	for (int i = 0; i < interfaceElements.size(); ++i)
	{
		//if (interfaceElements[i]->isUpdated)
			interfaceElements[i]->draw(this);
	}
	drawDeadTokens();
}

void Interface::drawDeadTokens()
{
	InterfaceElement * interfaceElement;
	for (int i = 0; i < 6; i++)
	{
		if (timeLine[i]->isAlive == false)
		{
			interfaceElement = ressources.stringInterface["PlayerTimeLine_" + std::to_string((long double)i + 1)];
			loadCircle(interfaceElement->position.x, interfaceElement->position.y, 16, sf::Color(0, 0, 0, 130));
		}
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
	int posX = (event.mouse.getPosition(win).x - 10) / Settings::CASE_SIZE;
	int posY = (event.mouse.getPosition(win).y - 10) / Settings::CASE_SIZE;

	if (posX < Settings::MAP_WIDTH && posY < Settings::MAP_HEIGHT &&
		event.mouse.getPosition(win).x >= (Settings::CASE_SIZE) * posX + 9 &&
		event.mouse.getPosition(win).x <= (Settings::CASE_SIZE) * (posX + 1) + 4 &&
		event.mouse.getPosition(win).y >= (Settings::CASE_SIZE) * posY + 9 &&
		event.mouse.getPosition(win).y <= (Settings::CASE_SIZE) * (posY + 1) + 4)
	{
		newHoverCase = map.map[std::pair<int, int>(posX, posY)];
	}
	else
		newHoverCase = NULL;
	if (newHoverCase != hoverCase)
	{
		hoverCase = newHoverCase;
		update_HoverCase();
		update_HoverPlayer();
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
	//************************************************************************************qjouter points surchqrge nouvelle fonction dqnq referee
	(*referee)->changeCPT();
	firstSpellClick(NULL);
	update_CurrentPlayer();
	updateTimeLine();
}

void Interface::setTimeLine()
{
	for (int i = 0; i < 6; i++)
	{
		((InterfaceElementImage *) ressources.stringInterface["PlayerTimeLine_" + std::to_string((long double)i + 1)])->updateTexture(& ressources.unitTexture[timeLine[i]->type]);
	}
	updateTimeLine();
}

void Interface::updateTimeLine()
{
	InterfaceElement * interfaceElement;
	for (int i = 0; i < 6; i++)
	{
		if (timeLine[i]->isPlaying)
		{
			interfaceElement = ressources.stringInterface["PlayerTimeLine_" + std::to_string((long double)i + 1)];
			loadCircle(interfaceElement->position.x - 4, interfaceElement->position.y - 4, 20, sf::Color(250, 250, 60));
		}
	}
}

void Interface::firstSpellClick(void *)
{
	update_Skill(0);
	
}

void Interface::secondSpellClick(void *)
{
	update_Skill(1);
}

void Interface::thirdSpellClick(void *)
{
	update_Skill(2);
}


void Interface::update_Skill(int skillNumber)
{
	((InterfaceElementText *) ressources.stringInterface["Skill_Description"])->updateString((*currentPlayerTurn)->spells[skillNumber]->description);
	((InterfaceElementText *) ressources.stringInterface["Skill_Cost"])->updateString("Cost  " + std::to_string((long double)(*currentPlayerTurn)->spells[skillNumber]->cost) + " AP");
	spell = (*currentPlayerTurn)->spells[skillNumber];
	int effectNumber = 1;
	int effectMax = 3;
	update_Skill_Duration(skillNumber);
	update_Skill_Life(& effectNumber, skillNumber);
	update_Skill_Move(& effectNumber, skillNumber);
	update_Skill_Action(& effectNumber, skillNumber);
	update_Skill_Teleport(& effectNumber, skillNumber);
	update_Skill_Displace(& effectNumber, skillNumber);
	while (effectNumber <= effectMax)
	{
		((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)effectNumber)])->updateString("");
		effectNumber++;
	}
}

void Interface::update_Skill_Duration(int skillNumber)
{
	std::string newString;
	if ((*currentPlayerTurn)->spells[skillNumber]->effect)
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->duration > 0)
		{
			newString = std::to_string((long double)(*currentPlayerTurn)->spells[skillNumber]->effect->duration) + "  hit";
			if ((*currentPlayerTurn)->spells[skillNumber]->effect->duration > 1)
				newString += "s"; 
		}
		else
		{
			newString = "Infinite duration";
		}
	}
	else
	{
		newString = "";
	}

	((InterfaceElementText *) ressources.stringInterface["Skill_Duration"])->updateString(newString);
}

void Interface::update_Skill_Life(int * effectNumber, int skillNumber)
{
	std::string newString = "";

	if ((*currentPlayerTurn)->spells[skillNumber])
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->life != 0)
		{
			if ((*currentPlayerTurn)->spells[skillNumber]->effect->life > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->life) + " HP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_Skill_Move(int * effectNumber, int skillNumber)
{
	std::string newString = "";

	if ((*currentPlayerTurn)->spells[skillNumber]->effect)
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->move_points != 0)
		{
			if ((*currentPlayerTurn)->spells[skillNumber]->effect->move_points > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->move_points) + " MP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_Skill_Action(int * effectNumber, int skillNumber)
{
	std::string newString = "";

	if ((*currentPlayerTurn)->spells[skillNumber]->effect)
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->action_points != 0)
		{
			if ((*currentPlayerTurn)->spells[skillNumber]->effect->action_points > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->action_points) + " AP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_Skill_Teleport(int * effectNumber, int skillNumber)
{
	std::string newString;

	if ((*currentPlayerTurn)->spells[skillNumber]->effect)
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->teleport.x != -1 && (*currentPlayerTurn)->spells[skillNumber]->effect->teleport.y != -1)
		{
			newString = "Teleport to [" + std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->teleport.x) + ", " + std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->teleport.y) +"]";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_Skill_Displace(int * effectNumber, int skillNumber)
{
	std::string newString;

	if ((*currentPlayerTurn)->spells[skillNumber]->effect)
	{
		if ((*currentPlayerTurn)->spells[skillNumber]->effect->displace.x != 0 && (*currentPlayerTurn)->spells[skillNumber]->effect->displace.y != 0)
		{
			newString = "Move from [" + std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->displace.x) + ", " + std::to_string((long double) (*currentPlayerTurn)->spells[skillNumber]->effect->displace.y) +"]";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["Skill_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::mainMenuClick(void *)
{
}

//
// Fonctions de mise à jour des données de l'interface
//

void Interface::update_HoverCase(void)
{
	update_HoverCase_Title();
	int effectNumber = 1;
	int effectMax = 3;
	update_HoverCase_Duration();
	update_HoverCase_Life(& effectNumber);
	update_HoverCase_Move(& effectNumber);
	update_HoverCase_Action(& effectNumber);
	update_HoverCase_Teleport(& effectNumber);
	update_HoverCase_Displace(& effectNumber);
	update_HoverCase_Wall(& effectNumber);
	while (effectNumber <= effectMax)
	{
		((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)effectNumber)])->updateString("");
		effectNumber++;
	}

	
}

void Interface::update_HoverCase_Title(void)
{
	std::string newString;
	if (hoverCase)
	{
		if (hoverCase->effect)
		{
			newString = "Case effect";
			((InterfaceElementText *) ressources.stringInterface["HoverCase_Title"])->position.x = Settings::INTERFACE_HOVER_CASE[0] + 75;
			((InterfaceElementText *) ressources.stringInterface["HoverCase_Title"])->updateText();
		}
		else
		{
			newString = "No effect on this case";
			((InterfaceElementText *) ressources.stringInterface["HoverCase_Title"])->position.x = Settings::INTERFACE_HOVER_CASE[0] + 20;
			((InterfaceElementText *) ressources.stringInterface["HoverCase_Title"])->updateText();
		}
	}
	else
		newString = ""; 
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Title"])->updateString(newString);
}

void Interface::update_HoverCase_Duration(void)
{
	std::string newString;
	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->duration > 0)
		{
			newString = std::to_string((long double)hoverCase->duration) + "  hit";
			if (hoverCase->duration > 1)
				newString += "s left";
			else
				newString += " left";
		}
		else
		{
			newString = "Infinite duration";
		}
	}
	else
	{
		newString = "";
	}

	((InterfaceElementText *) ressources.stringInterface["HoverCase_Duration"])->updateString(newString);
}

void Interface::update_HoverCase_Life(int * effectNumber)
{
	std::string newString = "";

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->life != 0)
		{
			if (hoverCase->effect->life > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) hoverCase->effect->life) + " HP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_HoverCase_Move(int * effectNumber)
{
	std::string newString = "";

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->move_points != 0)
		{
			if (hoverCase->effect->move_points > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) hoverCase->effect->move_points) + " MP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_HoverCase_Action(int * effectNumber)
{
	std::string newString = "";

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->action_points != 0)
		{
			if (hoverCase->effect->action_points > 0)
			{
				newString += "+";
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(79, 230, 6);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			else
			{
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->color = sf::Color(252, 32, 32);
				((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateText();
			}
			newString += std::to_string((long double) hoverCase->effect->action_points) + " AP";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_HoverCase_Teleport(int * effectNumber)
{
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->teleport.x != -1 && hoverCase->effect->teleport.y != -1)
		{
			newString = "Teleport to [" + std::to_string((long double) hoverCase->effect->teleport.x) + ", " + std::to_string((long double) hoverCase->effect->teleport.y) +"]";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_HoverCase_Displace(int * effectNumber)
{
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->displace.x != 0 && hoverCase->effect->displace.y != 0)
		{
			newString = "Move from [" + std::to_string((long double) hoverCase->effect->displace.x) + ", " + std::to_string((long double) hoverCase->effect->displace.y) +"]";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}

void Interface::update_HoverCase_Wall(int * effectNumber)
{
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->isWall)
		{
			newString = "Wall";
		}
		else
			return;
	}
	else
	{
		return;
	}
	((InterfaceElementText *) ressources.stringInterface["HoverCase_Effect_" + std::to_string((long double)(* effectNumber))])->updateString(newString);
	(* effectNumber)++;
}






void Interface::update_HoverPlayer(void)
{
	if (hoverCase && hoverCase->unit)
	{
		update_HoverPlayer_Team();
		update_HoverPlayer_Image();
		update_HoverPlayer_LifePoints();
		update_HoverPlayer_MovementsPoints();
		update_HoverPlayer_ActionPoints();
	}
	else
	{
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_Team"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_LifePoints"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_MovementPoints"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_ActionPoints"])->updateString("");
		((InterfaceElementImage *) ressources.stringInterface["HoverPlayer_Image"])->updateTexture(& ressources.texture["Empty_Token"]);
	}
}

void Interface::update_HoverPlayer_Team(void)
{
	std::string newString;
	newString = "Team " +  std::to_string((long double)hoverCase->unit->team_number + 1);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_Team"])->updateString(newString);
}

void Interface::update_HoverPlayer_Image(void)
{
	((InterfaceElementImage *) ressources.stringInterface["HoverPlayer_Image"])->updateTexture(& ressources.unitTexture[hoverCase->unit->type]);
}

void Interface::update_HoverPlayer_LifePoints(void)
{
	std::string newString;
	newString = std::to_string((long double)hoverCase->unit->life) + "  HP";
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_LifePoints"])->updateString(newString);
}

void Interface::update_HoverPlayer_MovementsPoints(void)
{
	std::string newString;
	newString = std::to_string((long double)hoverCase->unit->move_points) + "  MP";
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_MovementPoints"])->updateString(newString);
}

void Interface::update_HoverPlayer_ActionPoints(void)
{
	std::string newString;
	newString = std::to_string((long double)hoverCase->unit->action_points) + "  AP";
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_ActionPoints"])->updateString(newString);
}






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
	newString = "Team " +  std::to_string((long double)(*currentPlayerTurn)->team_number + 1);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_Team"])->updateString(newString);
}

void Interface::update_CurrentPlayer_Image(void)
{
	((InterfaceElementImage *) ressources.stringInterface["CurrentPlayer_Image"])->updateTexture(& ressources.unitTexture[(*currentPlayerTurn)->type]);
}

void Interface::update_CurrentPlayer_LifePoints(void)
{
	std::string newString;
	newString = std::to_string((long double)(*currentPlayerTurn)->life) + "   Health Point";
	if ((*currentPlayerTurn)->life > 1)
		newString += "s";
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_LifePoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_MovementsPoints(void)
{
	std::string newString;
	newString = std::to_string((long double)(*currentPlayerTurn)->move_points) + "   Movement Point";
	if ((*currentPlayerTurn)->move_points > 1)
		newString += "s";
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_MovementPoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_ActionPoints(void)
{
	std::string newString;
	newString = std::to_string((long double)(*currentPlayerTurn)->action_points) + "   Action Point";
	if ((*currentPlayerTurn)->action_points > 1)
		newString += "s";
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_ActionPoints"])->updateString(newString);
}

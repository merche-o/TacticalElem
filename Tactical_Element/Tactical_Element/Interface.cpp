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

	pushBackElement("CurrentPlayer_Team", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 10), 18, std::string("Team number Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_Image", new InterfaceElementImage(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 30), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("CurrentPlayer_LifePoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 100), 18, std::string("Life Points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_MovementPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 130), 18, std::string("Movements points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_ActionPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 160), 18, std::string("Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("CurrentPlayer_SurchargeActionPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 2 + 190), 18, std::string("Surcharge Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("HoverPlayer_Team", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, 10), 18, std::string("Team number Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_LifePoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, 100), 18, std::string("Life Points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_MovementPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, 130), 18, std::string("Movements points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_ActionPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, 160), 18, std::string("Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverPlayer_SurchargeActionPoints", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, 190), 18, std::string("Surcharge Action points Default Value"), sf::Color(255, 255, 255), interfaceFont));

	pushBackElement("HoverCase_Title", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 50, Settings::HEIGHT / 4 + 20), 18, std::string("HoverCase_Title default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Duration", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 20, Settings::HEIGHT / 4 + 45), 18, std::string("HoverCase_Duration default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_1", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 20, Settings::HEIGHT / 4 + 65), 18, std::string("HoverCase_Effect_1 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_2", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 20, Settings::HEIGHT / 4 + 85), 18, std::string("HoverCase_Effect_2 default value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("HoverCase_Effect_3", new InterfaceElementText(NULL, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 20, Settings::HEIGHT / 4 + 105), 18, std::string("HoverCase_Effect_3 default value"), sf::Color(255, 255, 255), interfaceFont));


	pushBackElement("PlayerTimeLine_1", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("PlayerTimeLine_2", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2 + 40, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("PlayerTimeLine_3", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2 + 80, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("PlayerTimeLine_4", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2 + 120, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("PlayerTimeLine_5", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2 + 160, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
	pushBackElement("PlayerTimeLine_6", new InterfaceElementImage(NULL, Pos((Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH) / 2 + 200, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT / 2), ressources.unitTexture[Unit::FIRE], ressources.unitTexture[Unit::FIRE]));
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
}

void Interface::updateTimeLine()
{
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
			newString = "Case effect :";
		else
			newString = "No effect on this case"; 
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
		if (hoverCase->effect->duration > 0)
		{
			newString = "Turns left : " + std::to_string((long double)hoverCase->effect->duration);
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
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->life != 0)
		{
			newString = std::to_string((long double) hoverCase->effect->life) + " HP";
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
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->move_points != 0)
		{
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
	std::string newString;

	if (hoverCase && hoverCase->effect)
	{
		if (hoverCase->effect->action_points != 0)
		{
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
		update_HoverPlayer_LifePoints();
		update_HoverPlayer_MovementsPoints();
		update_HoverPlayer_ActionPoints();
		update_HoverPlayer_SurchargeActionPoints();
	}
	else
	{
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_Team"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_LifePoints"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_MovementPoints"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_ActionPoints"])->updateString("");
		((InterfaceElementText *) ressources.stringInterface["HoverPlayer_SurchargeActionPoints"])->updateString("");
	}
}

void Interface::update_HoverPlayer_Team(void)
{
	std::string newString;
	newString = "Team : " +  std::to_string((long double)hoverCase->unit->team_number);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_Team"])->updateString(newString);
}

void Interface::update_HoverPlayer_LifePoints(void)
{
	std::string newString;
	newString = "Life : " +  std::to_string((long double)hoverCase->unit->life);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_LifePoints"])->updateString(newString);
}

void Interface::update_HoverPlayer_MovementsPoints(void)
{
	std::string newString;
	newString = "Movements : " +  std::to_string((long double)hoverCase->unit->move_points);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_MovementPoints"])->updateString(newString);
}

void Interface::update_HoverPlayer_ActionPoints(void)
{
	std::string newString;
	newString = "Actions : " +  std::to_string((long double)hoverCase->unit->action_points);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_ActionPoints"])->updateString(newString);
}

void Interface::update_HoverPlayer_SurchargeActionPoints(void)
{
	std::string newString;
	newString = "Surcharge action : " +  std::to_string((long double)hoverCase->unit->surcharge_action_points);
	((InterfaceElementText *) ressources.stringInterface["HoverPlayer_SurchargeActionPoints"])->updateString(newString);
}





void Interface::update_CurrentPlayer(void)
{
	update_CurrentPlayer_Team();
	update_CurrentPlayer_Image();
	update_CurrentPlayer_LifePoints();
	update_CurrentPlayer_MovementsPoints();
	update_CurrentPlayer_ActionPoints();
	update_CurrentPlayer_SurchargeActionPoints();
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
	newString = "Movements : " +  std::to_string((long double)(*currentPlayerTurn)->move_points);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_MovementPoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_ActionPoints(void)
{
	std::string newString;
	newString = "Actions : " +  std::to_string((long double)(*currentPlayerTurn)->action_points);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_ActionPoints"])->updateString(newString);
}

void Interface::update_CurrentPlayer_SurchargeActionPoints(void)
{
	std::string newString;
	newString = "Surcharge action : " +  std::to_string((long double)(*currentPlayerTurn)->surcharge_action_points);
	((InterfaceElementText *) ressources.stringInterface["CurrentPlayer_SurchargeActionPoints"])->updateString(newString);
}
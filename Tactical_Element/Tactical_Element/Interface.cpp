#include "Interface.h"

#include <iostream>

Interface::Interface(sf::RenderWindow & _window, Map & _map, Event & _event, std::vector<Team*> & _teams, Unit ** _currentPlayerTurn, Ressources & _ressources, Referee ** _referee)
	: Display(_window), map(_map), event(_event), teams(_teams), currentPlayerTurn(_currentPlayerTurn), ressources(_ressources), referee(_referee), hoverElement(NULL), clickedElement(NULL), mouseReleased(true)
{
	//interfaceElements.push_back(new InterfaceElementText(& endTurn, Pos(10, 10), 20, std::string("texte"), sf::Color(255, 255, 255), interfaceFont));
	//interfaceElements.push_back(new InterfaceElementImage(& endTurn, Pos(10, 10), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	pushBackElement("skill_1", new InterfaceElementImage(&Interface::firstSpellClick, Pos(50, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	pushBackElement("skill_2", new InterfaceElementImage(&Interface::secondSpellClick, Pos(150, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_2"], ressources.texture["skill_2_pressed"]));
	pushBackElement("skill_3", new InterfaceElementImage(&Interface::thirdSpellClick, Pos(250, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_3"], ressources.texture["skill_3_pressed"]));
	pushBackElement("skill_description", new InterfaceElementText(NULL, Pos(100, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 100), 20, std::string("Default Value"), sf::Color(255, 255, 255), interfaceFont));
	pushBackElement("end_turn", new InterfaceElementText(&Interface::endTurn, Pos(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH - 90, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), 20, std::string("End Turn"), sf::Color(255, 255, 255), interfaceFont));

}


Interface::~Interface(void)
{
}

void Interface::pushBackElement(std::string id, InterfaceElement * interfaceElement)
{
	interfaceElements.push_back(interfaceElement);
	ressources.stringInterface[id] = interfaceElement;
}

void Interface::run(void)
{
	sf::Vector2i	newMousePosition;
	bool			mouseClickStart;
	bool			mouseClickEnd;

	newMousePosition = event.mouse.getPosition(win);
	mouseClickStart = false;
	mouseClickEnd = false;
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
	sf::RectangleShape r;
	int thickness;
	thickness = 10;
	r.setFillColor(sf::Color(28, 47, 90, 255));
	r.setPosition(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + thickness, thickness);
	r.setSize(sf::Vector2f(Settings::INTERFACE_RIGHT_WIDTH - thickness * 2, Settings::HEIGHT - thickness * 2));
	r.setOutlineThickness(thickness);
	win.draw(r);
	//r.setFillColor(sf::Color(0, 255, 0, 255));
	r.setPosition(thickness, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + thickness);
	r.setSize(sf::Vector2f(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH - thickness * 1, Settings::INTERFACE_BOTTOM_HEIGHT - thickness * 2));
	win.draw(r);
	
	for (int i = 0; i < interfaceElements.size(); ++i)
	{
		//if (interfaceElements[i]->isUpdated)
			interfaceElements[i]->draw(this);
	}
}

void Interface::endTurn(void *)
{
	//std::cout << "endTurn" << std::endl;
	(*referee)->changeCPT();
	firstSpellClick(NULL);
	
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
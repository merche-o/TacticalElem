#include "Interface.h"

#include <iostream>

Interface::Interface(sf::RenderWindow & _window, Map & _map, Event & _event, std::vector<Team*> & _teams, Unit * _currentPlayerTurn, Ressources & _ressources)
	: Display(_window), map(_map), event(_event), teams(_teams), currentPlayerTurn(_currentPlayerTurn), ressources(_ressources), hoverElement(NULL), clickedElement(NULL), mouseReleased(true)
{
	//interfaceElements.push_back(new InterfaceElementText(& endTurn, Pos(10, 10), 20, std::string("texte"), sf::Color(255, 255, 255), interfaceFont));
	//interfaceElements.push_back(new InterfaceElementImage(& endTurn, Pos(10, 10), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	interfaceElements.push_back(new InterfaceElementImage(& firstSpellClick, Pos(50, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_1"], ressources.texture["skill_1_pressed"]));
	interfaceElements.push_back(new InterfaceElementImage(& secondSpellClick, Pos(150, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_2"], ressources.texture["skill_2_pressed"]));
	interfaceElements.push_back(new InterfaceElementImage(& thirdSpellClick, Pos(250, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT + 20), ressources.texture["skill_3"], ressources.texture["skill_3_pressed"]));
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
			clickedElement->mouseClickAction(NULL);
		}
		clickedElement->isClicked = false;
		//clickedElement->isUpdated = true;
		clickedElement = NULL;
	}
}


void Interface::draw(void)
{
	sf::RectangleShape r;
	r.setFillColor(sf::Color(220, 220, 220, 255));
	r.setPosition(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, 0);
	r.setSize(sf::Vector2f(Settings::INTERFACE_RIGHT_WIDTH, Settings::HEIGHT));
	win.draw(r);
	//r.setFillColor(sf::Color(0, 255, 0, 255));
	r.setPosition(0, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT);
	r.setSize(sf::Vector2f(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, Settings::INTERFACE_BOTTOM_HEIGHT));
	win.draw(r);
	
	for (int i = 0; i < interfaceElements.size(); ++i)
	{
		//if (interfaceElements[i]->isUpdated)
			interfaceElements[i]->draw(this);
	}
}

void endTurn(void *)
{
	//std::cout << "endTurn" << std::endl;
}

void firstSpellClick(void *)
{

}

void secondSpellClick(void *)
{

}

void thirdSpellClick(void *)
{

}
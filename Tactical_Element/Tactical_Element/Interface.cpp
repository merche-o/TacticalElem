#include "Interface.h"


Interface::Interface(sf::RenderWindow & _window, Map & _map, Event & _event, std::vector<Team*> & _teams, Unit * _currentPlayerTurn)
	: Display(_window), map(_map), event(_event), teams(_teams), currentPlayerTurn(_currentPlayerTurn)
{
	//interfaceElements.push_back(new InterfaceElementText(NULL, Pos(100, Settings::HEIGHT - 100), 20, std::string("TEST"), sf::Color(255, 255, 255), interfaceFont));
}


Interface::~Interface(void)
{
}

void Interface::run(void)
{
	sf::Vector2i newMousePosition;

	newMousePosition = event.mouse.getPosition();
	if (newMousePosition != mousePosition)
	{
		mousePosition = newMousePosition;
	}

	
}
void Interface::draw(void)
{
	/*
	sf::RectangleShape r;
	r.setFillColor(sf::Color(255, 0, 0, 255));
	r.setPosition(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, 0);
	r.setSize(sf::Vector2f(Settings::INTERFACE_RIGHT_WIDTH, Settings::HEIGHT));
	win.draw(r);
	r.setFillColor(sf::Color(0, 255, 0, 255));
	r.setPosition(0, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT);
	r.setSize(sf::Vector2f(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, Settings::INTERFACE_BOTTOM_HEIGHT));
	win.draw(r);
	*/
	for (int i = 0; i < interfaceElements.size(); ++i)
	{
		if (interfaceElements[i]->isUpdated)
			interfaceElements[i]->draw(this);
	}
}


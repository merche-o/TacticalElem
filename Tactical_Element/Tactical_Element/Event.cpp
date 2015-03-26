#include "Event.h"

#include <iostream>


Event::Event(sf::Window & w, Interface & i)
	: win(w), intface(i)
{
}


Event::~Event(void)
{
}

void Event::checkEvent()
{
	while (win.pollEvent(event))
    {
		if (event.type == sf::Event::Closed)
            win.close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				win.close();
				
		}
		else if (event.type == sf::Event::KeyReleased)
		{

		}
		else if (event.type == sf::Event::MouseMoved)
		{
			intface.changeMousePosition(event.mouseMove.x, event.mouseMove.y);
		}
    }
}


void Event::menuEvent(int & pos, bool & push, bool & refresh)
{
	while (win.pollEvent(event))
    {
		if (event.type == sf::Event::Closed)
            win.close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				win.close();
			else if (event.key.code == sf::Keyboard::Return)
			{
				push = true;
				refresh = true;
			}
			else if (event.key.code == sf::Keyboard::Up)
			{
				--pos;
				refresh = true;
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				++pos;
				refresh = true;
			}
		}
	}
}

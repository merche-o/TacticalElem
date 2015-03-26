#include "Event.h"
#include <iostream>

Event::Event(sf::Window & w)
	: win(w)
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
			//std::cout << mouse.getPosition(win).x << " / " << mouse.getPosition(win).y << std::endl;
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
			//else if (event.key.code == sf::Keyboard::Return)
			//{
			//	push = true;
			//	refresh = true;
			//}
			//else if (event.key.code == sf::Keyboard::Up)
			//{
			//	--pos;
			//	refresh = true;
			//}
			//else if (event.key.code == sf::Keyboard::Down)
			//{
			//	++pos;
			//	refresh = true;
			//}
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			refresh = true;
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed (sf::Mouse::Left))
			{
				push = true;
				refresh = true;
			}
		}
	}
}
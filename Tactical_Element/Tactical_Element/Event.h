#pragma once

#include "SFML\Graphics.hpp"

class Event
{
public:
	sf::Window & win;
	sf::Event event;

public:
	Event(sf::Window & w);
	~Event(void);
	
	void checkEvent();
	void menuEvent(int & pos, bool & push, bool & refresh);
};


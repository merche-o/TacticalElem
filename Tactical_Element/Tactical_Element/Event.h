#pragma once

#include "SFML\Graphics.hpp"
#include "Pos.h"

class Event
{
public:
	sf::Window & win;
	sf::Event event;
	sf::Mouse mouse;

public:
	Event(sf::Window & w);
	~Event(void);
	
	void checkEvent();
	void menuEvent(int & pos, bool & push, bool & refresh);
};


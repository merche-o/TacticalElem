#pragma once

#include "SFML\Graphics.hpp"
#include "Pos.h"
#include "Interface.h"

class Event
{
public:
	sf::Window & win;
	sf::Event event;
	Interface & intface;
	sf::Mouse mouse;

public:
	Event(sf::Window & w, Interface & i);
	~Event(void);
	
	void checkEvent();
	void menuEvent(int & pos, bool & push, bool & refresh);
};


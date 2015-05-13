#pragma once

#include "Pos.h"
#include "Display.h"

class GameMenu;

class ElementMenu : public Display
{
public:
	enum e_state
	{
		MAIN,
		TEAM_SELECTION,
		CREDITS,
		NONE
	};

public:
	Pos pos;
	e_state state;
	void(GameMenu:: *p)();
	bool lighted;

public:
	ElementMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)());
	~ElementMenu(void);

	void callFunction();
	virtual void draw() {};
	virtual void lightDraw() {};
	virtual sf::FloatRect getBounds() {return (sf::FloatRect());};
	virtual Unit * getUnitSelected() {return (NULL);};
	virtual std::string getStringText() {return (std::string(""));};
};


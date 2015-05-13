#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include "ElementMenu.h"

class TextMenu : public ElementMenu
{
public:
	int size;
	std::string text;
	sf::Color color;
	sf::Text menuText;
	sf::Font & font;


public:
	TextMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)(), std::string str, int size, sf::Font & Font, int r = 0, int g = 0, int b = 0);
	~TextMenu(void);

	virtual void draw();
	virtual void lightDraw();
	virtual sf::FloatRect getBounds();
	virtual Unit * getUnitSelected() {return (NULL);};
	virtual std::string getStringText();
};


#pragma once

#include <utility>
#include "Ressources.h"
#include "InterfaceElement.h"

class InterfaceElementText : public InterfaceElement
{	
public:
	sf::Text sfText;
	int size;
	std::string text;
	sf::Color color;
	sf::Font & font;

public:
	InterfaceElementText(MouseClickAction, Pos, int, std::string, sf::Color, sf::Font &);
	~InterfaceElementText(void);
	void updateText(int, std::string, sf::Color, sf::Font &);
	void updateText();

	virtual void draw(Display *);
};

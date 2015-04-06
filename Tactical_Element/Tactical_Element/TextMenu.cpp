#include "TextMenu.h"


TextMenu::TextMenu(float X, float Y, std::string t, int s, sf::Font & Font, int r, int g, int b)
	: x(X), y(Y), text(t), size(s), font(Font), color(r, g, b)
{
	menuText.setFont(font);

	menuText.setCharacterSize(s);
	menuText.setColor(sf::Color(r, g, b));
	menuText.setPosition(X, Y);
	menuText.setString(t);
}


TextMenu::~TextMenu(void)
{
}

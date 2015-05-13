#include "TextMenu.h"


TextMenu::TextMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)(), std::string str, int Size, sf::Font & Font, int r, int g, int b)
	: ElementMenu(w, X, Y, s, ptr), text(str), size(Size), font(Font), color(r, g, b)
{
	menuText.setFont(font);

	menuText.setCharacterSize(size);
	menuText.setColor(sf::Color(r, g, b));
	menuText.setPosition(X, Y);
	menuText.setString(str);
}

TextMenu::~TextMenu(void)
{
}

void TextMenu::draw()
{
	loadText(pos.x, pos.y, font, text, size, color.r, color.g, color.b);
	lighted = false;
}

void TextMenu::lightDraw()
{
	loadText(pos.x, pos.y, font, text, size, color.r, 250, color.b);
	lighted = true;
}

sf::FloatRect TextMenu::getBounds()
{
	return (menuText.getGlobalBounds());
}

std::string TextMenu::getStringText()
{
	return (text);
}
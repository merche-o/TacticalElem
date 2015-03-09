#include "Display.h"


Display::Display(sf::RenderWindow & w)
	: win(w)
{
	font.loadFromFile("../Ressources/Text/DragonForcE.ttf");
}


Display::~Display(void)
{
}

void Display::loadImage(float x, float y, sf::Texture & Texture, int transparency)
{
	sf::Sprite		Sprite;

	Sprite.setTexture(Texture);
	Sprite.setPosition(x, y);
	Sprite.setColor(sf::Color(255, 255, 255, transparency));
	win.draw(Sprite);
}

void Display::loadSprite(sf::Sprite Sprite)
{
	win.draw(Sprite);
}

void Display::loadUnit(Unit* unit)
{
	sf::Sprite	Sprite;

	Sprite.setTexture(unit->texture);
	win.draw(Sprite);
}

void Display::loadText(float x, float y, sf::Font font, std::string str, int size, int r, int g, int b)
{
	sf::Text text;

	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(sf::Color(r, g, b));
	text.setPosition(x, y);
	text.setString(str);
	win.draw(text);
}

void Display::RefreshWindow()
{
  win.display();
}
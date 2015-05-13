#include "Display.h"
#include "Settings.h"


Display::Display(sf::RenderWindow & w)
	: win(w)
{
	font.loadFromFile("../Ressources/Text/DragonForcE.ttf");
	interfaceFont.loadFromFile("../Ressources/Text/Roboto-Bold.ttf");
}


Display::~Display(void)
{
}

void Display::loadCircle(float x, float y, float radius, sf::Color color)
{
	sf::CircleShape circle;

	circle.setPosition(x, y);
	circle.setFillColor(color);
	circle.setRadius(radius);
	win.draw(circle);
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

	Sprite.setPosition(unit->pos.x * Settings::CASE_SIZE + 14, unit->pos.y * Settings::CASE_SIZE + 14);
	if (unit->isPlaying == true)
		loadCircle(unit->pos.x * Settings::CASE_SIZE + 10, unit->pos.y * Settings::CASE_SIZE + 10, 20, sf::Color(250, 250, 60));
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

void Display::loadText(sf::Text & text)
{
	win.draw(text);
}

//faire une fonction display::loadText avec un sf::Text en parametre seulement, que j'aurais init avant

void Display::RefreshWindow()
{
  win.display();
}
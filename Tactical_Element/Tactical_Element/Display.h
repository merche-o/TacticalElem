#pragma once

#include <SFML\Graphics.hpp>
#include "Unit.h"

class Display
{
public:
	sf::Font font;
	sf::Font fontSpecial;
	sf::Font interfaceFont;
	sf::RenderWindow & win;

public:
	Display(sf::RenderWindow & w);
	~Display(void);

	void loadCircle(float x, float y, float radius, sf::Color color);
	void loadImage(float x, float y, sf::Texture & texture, int transparency = 255);
	void loadSprite(sf::Sprite Sprite);
	void loadUnit(Unit* unit);
	void loadText(float, float, sf::Font, std::string, int size, int r, int g, int b);
	void loadText(sf::Text & text);
	void RefreshWindow();
};


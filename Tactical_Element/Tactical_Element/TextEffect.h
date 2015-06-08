#pragma once

#include "SFML\Graphics.hpp"
#include "Pos.h"
#include "Display.h"

class TextEffect : public Display
{
public:
	Pos pos;
	int size;
	std::string text;
	sf::Color color;
	sf::Text effectText;
	sf::Font & font;
	int time;

public:
	TextEffect(sf::RenderWindow & w, float X, float Y, std::string str, sf::Font & Font, int r = 0, int g = 0, int b = 0);
	~TextEffect(void);

	void draw();
};


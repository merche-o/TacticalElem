#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class TextMenu
{
public:
	float x;
	float y;
	int size;
	std::string text;
	sf::Color color;
	sf::Text menuText;
	sf::Font & font;

	// Une var pour la zone de clic

public:
	TextMenu(float X, float Y, std::string s, int size, sf::Font & Font, int r = 0, int g = 0, int b = 0);
	~TextMenu(void);
};


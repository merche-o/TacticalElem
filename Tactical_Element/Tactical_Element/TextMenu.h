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
	// Une var pour la zone de clic

public:
	TextMenu(float X, float Y, std::string s, int size, int r = 0, int g = 0, int b = 0);
	~TextMenu(void);
};


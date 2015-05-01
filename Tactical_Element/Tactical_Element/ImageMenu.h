#pragma once

#include <SFML\Graphics.hpp>
#include "Unit.h"

class ImageMenu
{
public:
	float x;
	float y;
	//sf::Texture & texture;
	Unit * unit;

public:
	ImageMenu(float X, float Y, Unit * u);
	~ImageMenu(void);
};


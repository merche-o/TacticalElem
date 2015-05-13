#include "ImageMenu.h"

#include <iostream>

ImageMenu::ImageMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)(), Unit * u)
	: ElementMenu(w, X, Y, s, ptr), unit(u)
{
	sprite.setTexture(unit->texture);
	sprite.setPosition(pos.x, pos.y);
}


ImageMenu::~ImageMenu(void)
{
}

void ImageMenu::draw()
{
	loadImage(pos.x, pos.y, unit->texture);
	lighted = false;
}

void ImageMenu::lightDraw()
{
	loadCircle(pos.x - 6, pos.y - 6, 22, sf::Color(250, 250, 60));
	loadImage(pos.x, pos.y, unit->texture);
	lighted = true;
}

sf::FloatRect ImageMenu::getBounds()
{
	return (sprite.getGlobalBounds());
}

Unit * ImageMenu::getUnitSelected()
{
	return (unit);
}
#include "InterfaceElementImage.h"

#include <iostream>

InterfaceElementImage::InterfaceElementImage(MouseClickAction _mouseClickAction, Pos _position, sf::Texture & _texture, sf::Texture & _clickedTexture, int _transparency)
	:	InterfaceElement(_mouseClickAction, _position),
	texture(_texture),
	clickedTexture(_clickedTexture),
	transparency(_transparency)
{
	height = 0;
	width = 0;
}

InterfaceElementImage::~InterfaceElementImage(void)
{
}

void	InterfaceElementImage::init(void)
{
	sf::Vector2u imageSize;

	imageSize = texture.getSize();
	height = imageSize.y;
	width = imageSize.x;
}

void InterfaceElementImage::draw(Display * display)
{
	if (height == 0)
		init();
	if (isClicked)
		display->loadImage(position.x, position.y, clickedTexture, transparency);
	else
		display->loadImage(position.x, position.y, texture, transparency);
	//isUpdated = false;
}
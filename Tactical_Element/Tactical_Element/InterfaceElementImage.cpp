#include "InterfaceElementImage.h"

InterfaceElementImage::InterfaceElementImage(MouseClickAction _mouseClickAction, Pos _position, sf::Texture & _texture, int _transparency)
	:	InterfaceElement(_mouseClickAction, _position),
	texture(_texture),
	transparency(_transparency)
{
	sf::Vector2u imageSize;

	imageSize = texture.getSize();
	height = imageSize.y;
	width = imageSize.x;
}

InterfaceElementImage::~InterfaceElementImage(void)
{
}

void InterfaceElementImage::draw(Display * display)
{
	display->loadImage(position.x, position.y, texture, transparency);
	//isUpdated = false;
}
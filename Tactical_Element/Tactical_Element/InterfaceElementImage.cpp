#include "InterfaceElementImage.h"

InterfaceElementImage::InterfaceElementImage(void(*_mousePressed)(void), Pos _position, sf::Texture & _texture, int _transparency)
	:	InterfaceElement(_mousePressed, _position),
	texture(_texture),
	transparency(_transparency)
{
}

InterfaceElementImage::~InterfaceElementImage(void)
{
}

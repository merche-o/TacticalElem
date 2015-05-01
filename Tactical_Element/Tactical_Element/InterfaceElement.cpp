#include "InterfaceElement.h"

#include <iostream>

InterfaceElement::InterfaceElement(MouseClickAction _mouseClickAction, Pos _position)
	:	mouseClickAction(_mouseClickAction),
		position(_position)
{
	if (mouseClickAction != NULL)
		isClickable = true;
	else
		isClickable = false;
	//isUpdated = true;
	isHover = false;
	isClicked = false;
}

InterfaceElement::~InterfaceElement(void)
{
}

bool InterfaceElement::mouseIntersection(sf::Vector2i & mousePosition)
{
	if (mousePosition.x < position.x ||
		mousePosition.x > position.x + width ||
		mousePosition.y - 4 < position.y ||
		mousePosition.y - 4 > position.y + height)
	{
		return false;
	}
	return true;
}
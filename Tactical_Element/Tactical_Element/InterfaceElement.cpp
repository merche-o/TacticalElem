#include "InterfaceElement.h"

InterfaceElement::InterfaceElement(void(*_mousePressed)(void), Pos _position)
	:	mousePressed(_mousePressed),
		position(_position)
{
	if (mousePressed != NULL)
		isClickable = false;
	else
		isClickable = true;
	isUpdated = true;
}

InterfaceElement::~InterfaceElement(void)
{
}
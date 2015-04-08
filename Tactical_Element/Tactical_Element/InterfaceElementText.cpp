#include "InterfaceElementText.h"


#include <iostream>


InterfaceElementText::InterfaceElementText(void(*_mousePressed)(void), Pos _position, int _size, std::string _text, sf::Color _color, sf::Font & _font)
	:	InterfaceElement(_mousePressed, _position),
		size(_size),
		text(_text),
		color(_color),
		font(_font)
{
	sf::FloatRect floatRect;

	sfText.setFont(font);
	sfText.setCharacterSize(size);
	sfText.setColor(color);
	sfText.setPosition(position.x, position.y);
	sfText.setString(text);
	floatRect = sfText.getGlobalBounds();
	width = floatRect.width;
	height = floatRect.height;
}

InterfaceElementText::~InterfaceElementText(void)
{
}

void InterfaceElementText::updateText(int size, std::string text, sf::Color color, sf::Font &font)
{
	sf::FloatRect floatRect;

	this->size = size;
	this->text = text;
	this->color = color;
	this->font = font;
	this->sfText.setFont(this->font);
	this->sfText.setCharacterSize(this->size);
	this->sfText.setColor(this->color);
	this->sfText.setPosition(position.x, position.y);
	this->sfText.setString(this->text);
	floatRect = this->sfText.getGlobalBounds();
	width = floatRect.width;
	height = floatRect.height;
	isUpdated = true;
}

void InterfaceElementText::draw(Display * display)
{
	display->loadText(sfText);
	isUpdated = false;
}
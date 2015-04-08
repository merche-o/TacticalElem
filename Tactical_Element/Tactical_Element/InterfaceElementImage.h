#pragma once

#include <utility>
#include "Ressources.h"
#include "InterfaceElement.h"

class InterfaceElementImage : public InterfaceElement
{	
public:
	sf::Texture & texture;
	int transparency;

public:
	InterfaceElementImage(void (*)(void), Pos, sf::Texture &, int = 255);
	~InterfaceElementImage(void);
};

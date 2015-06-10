#pragma once

#include <utility>
#include "Ressources.h"
#include "InterfaceElement.h"

class InterfaceElementImage : public InterfaceElement
{	
public:
	sf::Texture * texture;
	sf::Texture * clickedTexture;
	int transparency;

public:
	InterfaceElementImage(MouseClickAction, Pos, sf::Texture *, sf::Texture *, int = 255);
	~InterfaceElementImage(void);
	virtual void draw(Display *);
	void updateTexture(sf::Texture *);
	void init(void);
};

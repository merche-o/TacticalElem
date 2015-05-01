#pragma once

#include <utility>
#include "Ressources.h"
#include "Display.h"

typedef void (*MouseClickAction)(void *);

class InterfaceElement
{	
public:
	Pos position;
	MouseClickAction mouseClickAction;
	bool isClickable;
	//bool isUpdated;
	bool isHover;
	bool isClicked;
	int width;
	int height;

public:
	InterfaceElement(MouseClickAction, Pos);
	~InterfaceElement(void);

	bool mouseIntersection(sf::Vector2i &);
	virtual void draw(Display *){};
	// Il faut probablement faire une fonction pour tester si la souris est entre les bordures de l'element
};


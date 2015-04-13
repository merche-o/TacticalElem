#pragma once

#include <utility>
#include "Ressources.h"
#include "Display.h"

class InterfaceElement
{	
public:
	Pos position;
	void (*mousePressed)(void);
	bool isClickable;
	bool isUpdated;
	int width;
	int height;

public:
	InterfaceElement(void (*_mousePressed)(void), Pos);
	~InterfaceElement(void);

	virtual void draw(Display *){};
	// Il faut probablement faire une fonction pour tester si la souris est entre les bordures de l'element
};

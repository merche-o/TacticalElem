#include "Ressources.h"


Ressources::Ressources(void)
{
}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile(std::string fileName)
{
	// Textures
	//texture["****"].loadFromFile("../Ressources/Images/*****.png");
}


Unit *createBasicUnit()
{
	return new Unit(10, 10);
}
#include "Ressources.h"


Ressources::Ressources(void)
{
}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile()
{
	// Textures
	texture["test"].loadFromFile("../Ressources/Images/rouge.png");
}
#include "Ressources.h"


Ressources::Ressources(void)
{
}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile()
{
	texture["test"].loadFromFile("../Ressources/Images/rouge.png");
	
}


Unit *createBasicUnit()
{
	return new Unit(10, 10);


}
#include "Ressources.h"


Ressources::Ressources(void)
{
	//load unitTexture file par file
	unitTexture[Unit::FIRE].loadFromFile("../Ressources/Images/rouge.png");
	unitTexture[Unit::WATER].loadFromFile("../Ressources/Images/Token_Water.png");
	unitTexture[Unit::LIGHTENING].loadFromFile("../Ressources/Images/Token_Lightning.png");
	unitTexture[Unit::HEART].loadFromFile("../Ressources/Images/Token_Heart.png");
}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile()
{
	
}


Unit *createBasicUnit()
{
	return new Unit(10, 10);

//	texture["test"].loadFromFile("../Ressources/Images/rouge.png");

}
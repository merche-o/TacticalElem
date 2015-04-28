#include "Ressources.h"

#include <iostream>

Ressources::Ressources(void)
{

}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile()
{
	//	texture["test"].loadFromFile("../Ressources/Images/rouge.png");
	texture["skill_1"].loadFromFile("../Ressources/Images/Skill_I.png");
	texture["skill_1_pressed"].loadFromFile("../Ressources/Images/Skill_I_pressed.png");
	texture["skill_2"].loadFromFile("../Ressources/Images/Skill_II.png");
	texture["skill_2_pressed"].loadFromFile("../Ressources/Images/Skill_II_pressed.png");
	texture["skill_3"].loadFromFile("../Ressources/Images/Skill_III.png");
	texture["skill_3_pressed"].loadFromFile("../Ressources/Images/Skill_III_pressed.png");
}


Unit *createBasicUnit()
{
	return new Unit(10, 10);
}
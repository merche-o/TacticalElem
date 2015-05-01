#include "Ressources.h"

#include <iostream>

Ressources::Ressources(void)
{
	loadTexturesFromFile();
}


Ressources::~Ressources(void)
{
}


void Ressources::loadTexturesFromFile()
{
	texture["test"].loadFromFile("../Ressources/Images/rouge.png");
	
	texture["skill_1"].loadFromFile("../Ressources/Images/Skill_I.png");
	texture["skill_1_pressed"].loadFromFile("../Ressources/Images/Skill_I_pressed.png");
	texture["skill_2"].loadFromFile("../Ressources/Images/Skill_II.png");
	texture["skill_2_pressed"].loadFromFile("../Ressources/Images/Skill_II_pressed.png");
	texture["skill_3"].loadFromFile("../Ressources/Images/Skill_III.png");
	texture["skill_3_pressed"].loadFromFile("../Ressources/Images/Skill_III_pressed.png");



	//load unitTexture file par file
	unitTexture[Unit::FIRE].loadFromFile("../Ressources/Images/rouge.png");
	unitTexture[Unit::WATER].loadFromFile("../Ressources/Images/Token_Water.png");
	unitTexture[Unit::LIGHTNING].loadFromFile("../Ressources/Images/Token_Lightning.png");
	unitTexture[Unit::HEART].loadFromFile("../Ressources/Images/Token_Heart.png");
}
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
	texture["corner_TL"].loadFromFile("../Ressources/Images/corner_TL.png");
	texture["corner_TR"].loadFromFile("../Ressources/Images/corner_TR.png");
	texture["corner_BR"].loadFromFile("../Ressources/Images/corner_BR.png");
	texture["corner_BL"].loadFromFile("../Ressources/Images/corner_BL.png");
	texture["border_TB"].loadFromFile("../Ressources/Images/border_TB.png");
	texture["border_LR"].loadFromFile("../Ressources/Images/border_LR.png");



	//load unitTexture file par file
	unitTexture[Unit::FIRE].loadFromFile("../Ressources/Images/Token_Fire.png");
	unitTexture[Unit::WATER].loadFromFile("../Ressources/Images/Token_Water.png");
	unitTexture[Unit::LIGHTNING].loadFromFile("../Ressources/Images/Token_Lightning.png");
	unitTexture[Unit::HEART].loadFromFile("../Ressources/Images/Token_Heart.png");
	unitTexture[Unit::BARBARIAN].loadFromFile("../Ressources/Images/Token_Barbarian.png");
	unitTexture[Unit::MAGIC].loadFromFile("../Ressources/Images/Token_Magic.png");
	unitTexture[Unit::GHOST].loadFromFile("../Ressources/Images/Token_Ghost.png");
	unitTexture[Unit::KOREA].loadFromFile("../Ressources/Images/Token_Korea.png");
	unitTexture[Unit::PLANT].loadFromFile("../Ressources/Images/Token_Plant.png");
	unitTexture[Unit::YINYANG].loadFromFile("../Ressources/Images/Token_YinYang.png");
}
#pragma once

#include "SFML\Graphics.hpp"
#include <map>
#include "string"
#include <fstream>
#include "Unit.h"
#include "Spell.h"
#include "InterfaceElement.h"

class Ressources	
{
public:
	std::map<std::string, sf::Texture> texture;
	std::map<Unit::UnitType, sf::Texture> unitTexture;
	std::map<std::string, InterfaceElement *> stringInterface;

public:
	Ressources(void);
	~Ressources(void);

	void loadTexturesFromFile();
};


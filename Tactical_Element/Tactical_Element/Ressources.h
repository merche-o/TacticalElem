#pragma once

#include "SFML\Graphics.hpp"
#include <map>
#include "string"
#include <fstream>
#include "Unit.h"
#include "Spell.h"

class Ressources	
{
public:
	std::map<std::string, sf::Texture> texture;

public:
	Ressources(void);
	~Ressources(void);

	void loadTexturesFromFile();
};


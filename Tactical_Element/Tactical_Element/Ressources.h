#pragma once

#include "SFML\Graphics.hpp"
#include <map>
#include "string"

class Ressources
{
public:
	std::map<std::string, sf::Texture> texture;

public:
	Ressources(void);
	~Ressources(void);

	void loadTexturesFromFile(std::string fileName);
};


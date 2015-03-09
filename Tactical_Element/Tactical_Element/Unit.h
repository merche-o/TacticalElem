#pragma once

#include "SFML\Graphics.hpp"
#include <vector>
#include "Pos.h"
#include "Spell.h"

class Unit
{
public:
	Pos pos;
	int life;
	int initiative;
	int move_points;
	int action_points;
	std::vector<Spell*> spells;
	sf::Texture texture;
	// std::vector<Effect*> affliction; // Effets qui affecte le pion
	// std::vector<Effect*> effects; // Liste de pointeur sur les effets que ce pion a lancer et qui sont encore actif (pour le retrait temps a son debut de tour)

public:
	Unit(int X, int Y);
	~Unit(void);
};


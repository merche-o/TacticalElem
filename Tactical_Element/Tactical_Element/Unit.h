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
	int surcharge_action_points;
	std::vector<Spell*> spells;
	sf::Texture texture;
	sf::Color color;
	// std::vector<Effect*> afflictions; // Effets qui affecte le pion
	// std::vector<Effect*> effects; // Liste de pointeur sur les effets que ce pion a lancer et qui sont encore actif (pour le retrait temps a son debut de tour)

	int team_number;
	int player_number;

public:
	Unit(int X, int Y, int ini);
	~Unit(void);
};


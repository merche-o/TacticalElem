#pragma once

#include "SFML\Graphics.hpp"
#include <vector>
#include "Pos.h"
#include "Spell.h"

class Unit
{
public:
	enum UnitType
	{
		BASIC,
		FIRE,
		LIGHTENING,
		HEART,
		WATER,
	};

	Pos pos;
	int team;
	int player;
	int life;
	int initiative;
	int move_points;
	int action_points;
	int surcharge_action_points;
	std::vector<Spell*> spells;
	sf::Texture texture;

	UnitType type;
	// std::vector<Effect*> affliction; // Effets qui affecte le pion
	sf::Color color;
	// std::vector<Effect*> afflictions; // Effets qui affecte le pion

	// std::vector<Effect*> effects; // Liste de pointeur sur les effets que ce pion a lancer et qui sont encore actif (pour le retrait temps a son debut de tour)

	int team_number;
	int player_number;

public:
	Unit(int X, int Y);
	~Unit(void);
};


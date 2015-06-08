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
		LIGHTNING,
		HEART,
		WATER,
		BARBARIAN,
		MAGIC,
		GHOST,
		KOREA,
		PLANT,
		YINYANG
	};

	Pos pos;
	int life;
	int initiative;
	int move_points;
	int action_points;
	int surcharge_action_points;
	std::vector<Spell*> spells;
	sf::Texture & texture;

	UnitType type;
	sf::Color color;

<<<<<<< HEAD
=======
	// std::vector<Effect*> afflictions; // Effets qui affecte le pion
	// std::vector<Effect*> effects; // Liste de pointeur sur les effets que ce pion a lancer et qui sont encore actif (pour le retrait temps a son debut de tour)

>>>>>>> 9faa0e168f57eb3e1dedd38f2523dbaebdebe52d
	int team_number;
	int player_number;
	bool isPlaying;
	bool isAlive;

public:
	Unit(int X, int Y, sf::Texture & t);
	~Unit(void);

/*	Unit *Unit::createUnitWithType(Unit *u, int t, int p);
	std::map<Unit::UnitType, Unit *(Unit:: *)(Unit *u, int team ,int player)> factory;
	Unit *createWaterUnit(Unit *character, int nTeam, int nPlayer);
	Unit *createLightningUnit(Unit *character, int nTeam, int nPlayer);
	Unit *createHeartUnit(Unit *character, int nTeam, int nPlayer);
	Unit *createFireUnit(Unit *character, int nTeam, int nPlayer);
	Unit *createBarbarianUnit(Unit *character, int nTeam, int nPlayer);
	Unit *createMagicUnit(Unit *character, int nTeam, int nPlayer);*/
};


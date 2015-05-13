#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y)
	: pos(X, Y)
{
	this->factory[Unit::WATER] = &Unit::createWaterUnit;
	this->factory[Unit::LIGHTNING] = &Unit::createLightningUnit;
	this->factory[Unit::HEART] = &Unit::createHeartUnit;
}


Unit::~Unit(void)
{
}

Unit *Unit::createUnitWithType(Unit *u, int team, int player)
{
	return (this->*(factory[u->type]))(u, team, player);	
}

Unit *Unit::createWaterUnit(Unit *character, int nTeam, int nPlayer)
{
	character->type = Unit::WATER;
	team_number = nTeam;
	player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "Water 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "Water 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "Water 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);

	return character;
}


//have to edit this one
Unit *Unit::createLightningUnit(Unit *character, int nTeam, int nPlayer)
{
	character->type = Unit::LIGHTNING;
	team_number = nTeam;
	player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "L 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "L 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "L 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);

	return character;
}

Unit *Unit::createHeartUnit(Unit *character, int nTeam, int nPlayer)
{
	character->type = Unit::HEART;
	team_number = nTeam;
	player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "H 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "H 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "H 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);
	
	return character;
}
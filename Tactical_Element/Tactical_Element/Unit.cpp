#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y, sf::Texture & t)
	: pos(X, Y), texture(t)
{
	this->factory[Unit::WATER] = &Unit::createWaterUnit;
	this->factory[Unit::LIGHTNING] = &Unit::createLightningUnit;
	this->factory[Unit::HEART] = &Unit::createHeartUnit;

	isPlaying = false;
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
	character->spells.push_back(new Spell(4, "toto1"));
	character->spells.push_back(new Spell(3, "toto2"));
	character->spells.push_back(new Spell(2, "toto3"));
	character->pos.x = 0;
	character->pos.y = 0;
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
	character->spells.push_back(new Spell(4, "toto1"));
	character->spells.push_back(new Spell(4, "toto2"));
	character->spells.push_back(new Spell(4, "toto3"));
	character->pos.x = 0;
	character->pos.y = 0;
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
	character->spells.push_back(new Spell(4, "toto1"));
	character->spells.push_back(new Spell(4, "toto2"));
	character->spells.push_back(new Spell(4, "toto3"));
	character->pos.x = 0;
	character->pos.y = 0;
	return character;
}
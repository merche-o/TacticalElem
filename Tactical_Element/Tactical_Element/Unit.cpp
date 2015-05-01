#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y)
	: pos(X, Y)
{
}


Unit::~Unit(void)
{
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
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	
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
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	
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
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	
	return character;
}
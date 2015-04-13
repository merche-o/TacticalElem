#include "CharacterFactory.h"

//pour créer un nouveau type de Character/Unit crée une nouvelle fonction createXUnit (X etant le type)
// Regarder les commentaires dans createWaterUnit pour plus de details

CharacterFactory::CharacterFactory(void)
{
	this->factory[Unit::WATER] = &CharacterFactory::createWaterUnit;
	this->factory[Unit::ROCK] = &CharacterFactory::createRockUnit;
	this->factory[Unit::BASIC] = &CharacterFactory::createBasicUnit;
}


CharacterFactory::~CharacterFactory(void)
{
}

Unit *CharacterFactory::createBasicUnit(int x,int y, int team, int player)
{
	Unit *character = new Unit(x, y);
	character->team = team;
	character->player = player;
	return character;
}

Unit *CharacterFactory::createWaterUnit(int x, int y, int team, int player)
{
	Unit *character = createBasicUnit(x, y, team, player);
	character->type = Unit::WATER;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	//character->texture = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	
	return character;
}

Unit *CharacterFactory::createUnit(Unit::UnitType type, int x, int y, int team, int player)
{
	return (this->*(factory[type]))(x,y, team, player);	
}

//have to edit this one
Unit *CharacterFactory::createRockUnit(int x, int y, int team, int player)
{
	Unit *character = createBasicUnit(x, y, team, player);
	character->type = Unit::ROCK;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	//character->texture = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	character->spells.push_back(new SpellDirect(4));
	
	return character;
}
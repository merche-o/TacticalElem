#include "CharacterFactory.h"

//pour créer un nouveau type de Character/Unit crée une nouvelle fonction createXUnit (X etant le type)
// Regarder les commentaires dans createWaterUnit pour plus de details

CharacterFactory::CharacterFactory(Ressources & _res)
	: res(_res)
{
	this->factory[Unit::WATER] = &CharacterFactory::createWaterUnit;
	this->factory[Unit::LIGHTNING] = &CharacterFactory::createLightningUnit;
	this->factory[Unit::HEART] = &CharacterFactory::createHeartUnit;
	this->factory[Unit::FIRE] = &CharacterFactory::createFireUnit;
	this->factory[Unit::BARBARIAN] = &CharacterFactory::createBarbarianUnit;
	this->factory[Unit::MAGIC] = &CharacterFactory::createMagicUnit;
}


CharacterFactory::~CharacterFactory(void)
{
}


Unit *CharacterFactory::createUnit(Ressources & ress, Unit::UnitType type)
{
	Unit *character = new Unit(0, 0, ress.unitTexture[type]);
	character->type = type;
	//character->texture = res.texture["test"];
	//character->texture = res.unitTexture[character->type];
	return (character);
}

Unit *CharacterFactory::createUnitWithType(Unit::UnitType u, int team, int player, Ressources &_res)
{
	return (this->*(factory[u]))(team, player, _res);	
}

Unit *CharacterFactory::createWaterUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::WATER]); 
	character->team_number = nTeam;
	character->player_number = nPlayer;
	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 2;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "Water 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "Water 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "Water 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);
	character->pos.x = 0;
	character->pos.y = 0;
	return character;
}


//have to edit this one
Unit *CharacterFactory::createLightningUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::LIGHTNING]);
	character->team_number = nTeam;
	character->player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 2;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "L 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "L 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "L 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);

	character->pos.x = 0;
	character->pos.y = 0;
	return character;
}

Unit *CharacterFactory::createHeartUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::HEART]);
	character->team_number = nTeam;
	character->player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 2;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "H 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "H 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "H 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);
	
	character->pos.x = 0;
	character->pos.y = 0;
	return character;
}

Unit *CharacterFactory::createFireUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::FIRE]);
	character->team_number = nTeam;
	character->player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 2;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "F 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "F 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "F 3 : Create a wall"));
	
	character->spells[0]->effect->setLife(-3);
	character->spells[1]->effect->setLife(1);
	character->spells[2]->effect->setWall(true);
	
	character->pos.x = 0;
	character->pos.y = 0;
	return character;
}

Unit *CharacterFactory::createBarbarianUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::BARBARIAN]);
	character->team_number = nTeam;
	character->player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "F 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "F 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "F 3 : Create a wall"));
	
	return character;
}

Unit *CharacterFactory::createMagicUnit(int nTeam, int nPlayer, Ressources &_res)
{
	Unit *character = new Unit(0, 0, _res.unitTexture[Unit::MAGIC]);
	character->team_number = nTeam;
	character->player_number = nPlayer;

	//il faut attribuer au character ces caracteristiques suivant le type
	character->life  = 5;
	character->initiative = 5;
	character->move_points = 5;
	
	//push les spells suivant le type dans la spell list du character
	character->spells.push_back(new Spell(2, 0, "F 1 : Damage"));
	character->spells.push_back(new Spell(2, 0, "F 2 : Heal"));
	character->spells.push_back(new Spell(2, 0, "F 3 : Create a wall"));
	
	return character;
}
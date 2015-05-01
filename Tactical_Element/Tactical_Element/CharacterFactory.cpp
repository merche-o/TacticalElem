#include "CharacterFactory.h"

//pour créer un nouveau type de Character/Unit crée une nouvelle fonction createXUnit (X etant le type)
// Regarder les commentaires dans createWaterUnit pour plus de details

CharacterFactory::CharacterFactory(Ressources &_res): res(_res)
{
}


CharacterFactory::~CharacterFactory(void)
{
}


Unit *CharacterFactory::createUnit(Unit::UnitType type)
{
	Unit *character = new Unit(0, 0);
	character->type = type;
	character->texture = res.unitTexture[character->type];
	return character;
		
}


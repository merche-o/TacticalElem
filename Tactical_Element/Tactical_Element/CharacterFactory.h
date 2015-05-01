#pragma once

#include <map>
#include "Unit.h"
#include "Spell.h"
#include "SpellDirect.h"
#include "Ressources.h"

class CharacterFactory
{
private:
Ressources &res; 

public:
	CharacterFactory(Ressources &_res);
	~CharacterFactory(void);
	//void(IA:: *)(Enemy *src, float x, float y);
	//pointeur sur func

	Unit *createUnit(Unit::UnitType);
};


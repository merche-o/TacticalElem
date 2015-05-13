#pragma once

#include <map>
#include "Unit.h"
#include "Spell.h"
#include "SpellDirect.h"
#include "Ressources.h"

class CharacterFactory
{
public:
	Ressources & res; 

public:
	CharacterFactory(Ressources &_res);
	~CharacterFactory(void);
	//void(IA:: *)(Enemy *src, float x, float y);
	//pointeur sur func

	Unit *createUnit(Ressources & res, Unit::UnitType);
};


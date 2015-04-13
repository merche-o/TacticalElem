#pragma once

#include <map>
#include "Unit.h"
#include "Spell.h"
#include "SpellDirect.h"
#include "Ressources.h"

class CharacterFactory
{
public:
	CharacterFactory(void);
	~CharacterFactory(void);
	//void(IA:: *)(Enemy *src, float x, float y);
	//pointeur sur func

	Unit *createUnit(Unit::UnitType, int x, int y, int team, int player);
	Unit *createBasicUnit(int x, int y, int team, int player);
	Unit *createWaterUnit(int x, int y, int team, int player);
	Unit *createRockUnit(int x, int y, int team, int player);
	std::map<Unit::UnitType, Unit *(CharacterFactory:: *)(int x, int y, int team ,int player)> factory;
};


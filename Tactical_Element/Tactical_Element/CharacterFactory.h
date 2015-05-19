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
	Unit *createUnitWithType(Unit::UnitType u, int t, int p, Ressources &_res);
	std::map<Unit::UnitType, Unit *(CharacterFactory:: *)(int team ,int player, Ressources &_res)> factory;
	Unit *createWaterUnit(int nTeam, int nPlayer, Ressources &_res);
	Unit *createLightningUnit(int nTeam, int nPlayer, Ressources &_res);
	Unit *createHeartUnit(int nTeam, int nPlayer, Ressources &_res);
	Unit *createFireUnit(int nTeam, int nPlayer, Ressources &_res);
	Unit *createBarbarianUnit(int nTeam, int nPlayer, Ressources &_res);
	Unit *createMagicUnit(int nTeam, int nPlayer, Ressources &_res);
};


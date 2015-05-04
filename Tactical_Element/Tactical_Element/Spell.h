#pragma once

#include "Effect.h"
#include <string>

class Spell
{
public:
	int range;
	std::string description;
	Effect* effect;

public:
	Spell(int Range, std::string Desc);
	~Spell(void);

	virtual void active();
};


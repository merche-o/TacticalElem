#pragma once

#include "Effect.h"

class Spell
{
public:
	int range;

	Effect* effet;

public:
	Spell(int Range);
	~Spell(void);

	virtual void active();
};


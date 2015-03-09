#pragma once

#include "Spell.h"

class SpellDirect : public Spell
{
public:
	SpellDirect(int Range);
	~SpellDirect(void);

	void active();
};


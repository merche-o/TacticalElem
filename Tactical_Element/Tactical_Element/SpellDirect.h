#pragma once

#include "Spell.h"

class SpellDirect : public Spell
{
public:
	SpellDirect(int Range, std::string description);
	~SpellDirect(void);

	void active();
};


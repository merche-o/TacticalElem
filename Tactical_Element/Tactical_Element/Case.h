#pragma once

#include "Effect.h"
#include "Unit.h"
class Case
{
public:
	Effect	*effect; // Glyphe d'effet
	Unit	*unit;
	bool	immune;	
public:
	Case(void);
	~Case(void);
};


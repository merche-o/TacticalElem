#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y, int ini)
	: pos(X, Y), initiative(ini)
{
	spells.push_back(new SpellDirect(4));
}


Unit::~Unit(void)
{
}

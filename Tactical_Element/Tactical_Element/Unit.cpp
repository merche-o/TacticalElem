#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y)
	: pos(X, Y)
{
	spells.push_back(new SpellDirect(4));
}


Unit::~Unit(void)
{
}

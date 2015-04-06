#include "Unit.h"
#include "SpellDirect.h"

Unit::Unit(int X, int Y, int ini)
	: pos(X, Y), initiative(ini)
{
}


Unit::~Unit(void)
{
}

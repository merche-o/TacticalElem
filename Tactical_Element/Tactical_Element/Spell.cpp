#include "Spell.h"


Spell::Spell(int Range, int Cost, std::string Desc)
	: range(Range), cost(Cost), description(Desc), overWrite(false)
{
	effect = new Effect();
}


Spell::~Spell(void)
{
}

void Spell::active()
{

}

void Spell::setDesc(std::string newDesc)
{
	description = newDesc;
}

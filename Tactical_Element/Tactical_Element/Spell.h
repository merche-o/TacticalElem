#pragma once

#include "Effect.h"
#include <string>

class Spell
{
public:
	int range;
	std::string description;
	Effect* effect;
	int cost;

public:
	Spell(int Range, int Cost, std::string Desc);
	~Spell(void);
	void setDesc(std::string newDesc);

	virtual void active();
};


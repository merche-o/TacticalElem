#pragma once

#include "Effect.h"
#include <string>

class Spell
{
public:

	enum SpellType
	{
		GLYPHE,
		HORIZONTAL,
		VERTICAL,
		DIRECT
	};

	// Faire l'exemple du barbare
	int range;
	std::string description;
	Effect* effect;
	int cost;
	SpellType type;
	bool overWrite;
	// 
public:
	Spell(int Range, int Cost, std::string Desc);
	~Spell(void);
	void setDesc(std::string newDesc);

	virtual void active();
};


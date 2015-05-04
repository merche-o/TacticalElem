#pragma once
#include "Team.h"
#include "Map.h"


class Referee
{
public:
	std::vector<Team*> teams;
	Map & map;
public:
	Referee(std::vector<Team*> Teams, Map & Map);
	~Referee(void);

	bool canPlay(Unit unit);

	void castSpell(Spell spell, Pos pos);

	void applyEffectOnCase(Case *_case, Effect *effect);

	void applyEffectToPlayer(Case *_case);

	bool checkMove(Pos pos);

	void decreaseDuration(Case *_case);

	bool gameOver(std::vector<Team*>teams);
};


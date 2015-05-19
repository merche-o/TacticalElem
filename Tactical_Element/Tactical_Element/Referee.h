#pragma once
#include "Team.h"
#include "Map.h"
#include "Unit.h"



class Referee
{
public:
	std::vector<Team*>& teams;
	Map & map;
	Unit ** currentPlayerTurn;

public:
	Referee(std::vector<Team*> &Teams, Map & Map, Unit **);
	~Referee(void);

	bool canPlay(Unit unit);

	void castSpell(Spell *spell, std::map<std::pair<int, int>, bool> effectArea);

	void applyEffectOnCase(Case *_case, Effect *effect);

	void applyEffectToPlayer(Case *_case);

	bool checkMove(Pos pos);

	void decreaseDuration(Case *_case);

	bool gameOver(std::vector<Team*>teams);

	void changeCPT(void);

	void killPlayer();
};


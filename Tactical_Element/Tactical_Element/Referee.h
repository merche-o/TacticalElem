#pragma once
#include "Team.h"
#include "Map.h"
#include "Unit.h"



class Referee
{
public:
	std::vector<Team*> & teams;
	std::vector<Unit*> & timeLine;
	int indexTimeLine;
	Map & map;
	Unit ** currentPlayerTurn;

public:
	Referee(std::vector<Team*> & Teams, std::vector<Unit*> & TimeLine, Map & Map, Unit **);
	~Referee(void);

	bool canPlay(Unit unit);

	void castSpell(Spell *spell, std::map<std::pair<int, int>, bool> effectArea);

	void applyEffectOnCase(Case *_case, Effect *effect);

	void applyEffectToPlayer(Case *_case);

	bool checkMove(Pos *pos);

	void decreaseDuration(Case *_case);

	bool gameOver();

	void changeCPT(void);

	void killPlayer();

	bool canCast(Spell *spell);

	int distance(Pos *pos1, Pos *pos2);
};


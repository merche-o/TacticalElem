#include "Referee.h"
#include <stdlib.h>
#include <cstdlib>

Referee::Referee(std::vector<Team*> & Teams, std::vector<Unit*> & TimeLine, Map & Map, Unit ** Unit)
	: teams(Teams), timeLine(TimeLine), map(Map), currentPlayerTurn(Unit)
{
	indexTimeLine = 0;
}

Referee::~Referee(void)
{

}

void Referee::applyEffectToPlayer(Case *_case)
{
	if (_case->immune == false && _case->effect != NULL)
	{
		_case->unit->life += _case->effect->life;
		if (_case->effect->teleport.x != -1 && _case->effect->teleport.y != -1)
			_case->unit->pos = _case->effect->teleport;
		_case->unit->pos.x += _case->effect->displace.x;
		_case->unit->pos.y += _case->effect->displace.y;
		_case->unit->action_points += _case->effect->action_points;
		_case->unit->move_points += _case->effect->move_points;
	}
}

void Referee::applyEffectOnCase(Case *_case, Effect *effect)
{
	if (_case->effect == NULL)
	{
		_case->effect = new Effect();
		_case->effect = effect;
	}
}


bool Referee::canPlay(Unit unit)
{
	if (unit.action_points > 0)
		return (true);
	else
		return (false);
}

bool Referee::checkMove(Pos *pos)
{
		if ((*currentPlayerTurn)->move_points >= 1)
		{
		Case *tmp;
		tmp = map.getCase(pos->x, pos->y);

		if (tmp->effect == NULL)
		{
			if (tmp->unit != NULL)
				return (false);
			return (true);
		}
		else
		{
			if (tmp->effect->isWall == true || tmp->unit != NULL)
				return (false);
			return (true);
		}
	}
		return (false);
}

void Referee::decreaseDuration(Case *_case)
{
	_case->effect->duration -=1;
	if (_case->effect->duration <= 0)
		_case->effect = NULL;
}

void Referee::castSpell(Spell *spell, std::map<std::pair<int, int>, bool> affectArea)
{
	for (int y = 0; y < Settings::MAP_HEIGHT; ++y)
	{
		for (int x = 0; x < Settings::MAP_WIDTH; ++x)
		{
			// Dois changer couleur/sprite suivant les proprietes de la case;
			
			if (this->map.map[std::make_pair(x, y)] && affectArea[std::make_pair(x,y)] == true)
			{
				applyEffectOnCase(this->map.map[std::make_pair(x, y)], spell->effect);
			}
		}
	}
}

void Referee::changeCPT()
{
	if (teams[(*currentPlayerTurn)->team_number]->units[0]->isAlive == false
		&& teams[(*currentPlayerTurn)->team_number]->units[1]->isAlive == false
		&& teams[(*currentPlayerTurn)->team_number]->units[2]->isAlive == false)
	{
		std::cout << "WIN" << std::endl;
		exit(0);
	}

	// Change player turn
	(*currentPlayerTurn)->isPlaying = false;

	indexTimeLine++;
	if (indexTimeLine >= timeLine.size())
			indexTimeLine = 0;
	while (timeLine[indexTimeLine]->isAlive == false)
	{
		indexTimeLine++;
		if (indexTimeLine >= timeLine.size())
			indexTimeLine = 0;
	}

	(*currentPlayerTurn) = timeLine[indexTimeLine];
	(*currentPlayerTurn)->isPlaying = true;

	applyEffectToPlayer(map.getCase((*currentPlayerTurn)->pos.x, (*currentPlayerTurn)->pos.y));
	// Ajouter le dot damage
	killPlayer();
}

void Referee::killPlayer()
{
	if ((*currentPlayerTurn)->life <= 0)
	{
		(*currentPlayerTurn)->isAlive = false;
		map.getCase((*currentPlayerTurn)->pos.x, (*currentPlayerTurn)->pos.y)->unit = NULL;
		(*currentPlayerTurn)->pos.x = -1;
		(*currentPlayerTurn)->pos.y = -1;
		changeCPT();
		//teams[(*currentPlayerTurn)->team_number]->units.erase(teams[(*currentPlayerTurn)->team_number]->units.begin() + (*currentPlayerTurn)->team_number);
		//changeCPT();
	}
}

bool Referee::canCast(Spell *spell)
{// retirer le cout du sort
	if ((*currentPlayerTurn)->action_points >= spell->cost)
		return (true);
	return (false);
}

int Referee::distance(Pos *pos1, Pos *pos2)
{
	return (abs(pos1->x - pos2->x) + abs(pos1->y - pos2->y));
}

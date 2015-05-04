#include "Referee.h"


Referee::Referee(std::vector<Team*> Teams, Map & Map)
	: teams(Teams), map (Map)
{

}

Referee::~Referee(void)
{

}

void Referee::applyEffectToPlayer(Case *_case)
{
	if (_case->immune == false && _case->effect != NULL)
	{
		_case->unit->life -= _case->effect->life;
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
	if (_case->effect != NULL)
		_case->effect = new Effect();
	_case->effect = effect;
}


bool Referee::canPlay(Unit unit)
{
	if (unit.action_points > 0)
		return (true);
	else
		return (false);
}

bool Referee::checkMove(Pos pos)
{
	Case *tmp;

	tmp = map.getCase(pos.x, pos.y);
	if (tmp->effect->isWall == true || tmp->unit != NULL)
		return (false);
	else
		return (true);
}

void Referee::decreaseDuration(Case *_case)
{
	_case->effect->duration -=1;

}
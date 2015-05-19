#include "Referee.h"


Referee::Referee(std::vector<Team*> & Teams, Map & Map, Unit ** Unit)
	: teams(Teams), map(Map), currentPlayerTurn(Unit)
{

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
	applyEffectToPlayer(map.getCase((*currentPlayerTurn)->pos.x, (*currentPlayerTurn)->pos.y));
		std::cout << "Life du Player :" << (*currentPlayerTurn)->life << std::endl;
	killPlayer();
	int CPT_team = (*currentPlayerTurn)->team_number;
	int CPT_num = (*currentPlayerTurn)->player_number;

	//log
	//std::cout << "-----" << std::endl << "player nb " << CPT_num << std::endl;
	//std::cout << "team nb " << CPT_team << std::endl;
	
	(*currentPlayerTurn)->isPlaying = false;
	if (CPT_team == 0)
		(*currentPlayerTurn) = teams[1]->units[(*currentPlayerTurn)->player_number];
	else if (CPT_team == 1)
	{
		if (CPT_num == 2) // Max team's players
			CPT_num = -1;
		(*currentPlayerTurn) = teams[0]->units[CPT_num + 1];
	}

	(*currentPlayerTurn)->isPlaying = true;

	//log
	//(*currentPlayerTurn) = teams[0]->units[1];
	//std::cout << "-----" << std::endl << "player nb " << teams[0]->units[1]->player_number << std::endl;
	 //std::cout << "team nb " << teams[0]->units[1]->team_number << std::endl;
}

void Referee::killPlayer()
{
	if ((*currentPlayerTurn)->life <= 0)
		teams[(*currentPlayerTurn)->team_number]->units.erase(teams[(*currentPlayerTurn)->team_number]->units.begin() + (*currentPlayerTurn)->team_number);
	std::cout << "Taille team : " << teams[(*currentPlayerTurn)->team_number]->units.size() << std::endl;
	if (teams[(*currentPlayerTurn)->team_number]->units.size() == 0)
	{
		std::cout << "WIN" << std::endl;
		exit(0);
	}
}
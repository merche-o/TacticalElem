#include "GameEngine.h"


GameEngine::GameEngine(void)
	: ressources(),
	factoryUnit(ressources),
	menu(window, event, ressources, teams, factoryUnit, restart),
	sound(),
	map(),
	intface(window, map, event, teams, & currentPlayerTurn, ressources, & ref, timeLine),
	graphic(window, map, ressources, teams),
	event(window)
{
	menu.createMenu();
	state = MENU;
	
	sound.musicOFF();
	sound.playMusic(sound.music);

	window.create(sf::VideoMode(Settings::WIDTH, Settings::HEIGHT, Settings::CASE_SIZE), Settings::GAME_NAME);
	window.setFramerateLimit(30);

	restart = false;

	// For Testing Only ////////////////
	teams.push_back(new Team());
	teams.push_back(new Team());

	ref = new Referee(teams, timeLine, map, & currentPlayerTurn);
	released = true;
	/////////////////////////////////////
}


GameEngine::~GameEngine(void)
{
}

void GameEngine::run()
{
	while (window.isOpen())
	{
		if (state == MENU)
		{
			menu.run();
			
			if (restart == true)
				state = GAME;
		}
		else if (state == GAME)
		{
			if (restart == true)
			{
				createTimeLine();
				this->selectFirstPlayer();
				intface.spell = currentPlayerTurn->spells[0];
				intface.update_CurrentPlayer();
				intface.update_HoverCase();
				intface.update_HoverPlayer();
				intface.firstSpellClick(NULL);
				intface.setTimeLine();
				restart = false;
				released = true;
			}
			// Au tout debut du tour d'un pion, retirer 1 tour d'effet (case/zone/buff/debuff) a son nom sur la map
	
			// Action Functions
			event.checkEvent();
			Pos *tmp = getMouseCoordinateOnMap();
			intface.run();
			//////////
			
			// Display Functions
			window.clear();
			// graphic.drawUnits();

			if (tmp != NULL)
			{
				if (intface.spell->effect->isWall == true)
					map.showEffectArea(tmp->x, tmp->y, intface.spell->range, true);
				else
					map.showEffectArea(tmp->x, tmp->y, intface.spell->range, false);
			}
			else
				map.effectArea.clear();
			
			if (event.mouse.isButtonPressed(sf::Mouse::Button::Left) && tmp != NULL && map.effectArea.size() > 0)
			{
				released = false;
				//graphic.addTextEffect(tmp->x * Settings::CASE_SIZE, tmp->y * Settings::CASE_SIZE, std::string("-10"), sf::Color(255, 60, 0));
			}
			else if (!event.mouse.isButtonPressed(sf::Mouse::Button::Left) && tmp != NULL && map.effectArea.size() > 0)
			{
				if (released == false)
				{
					if (currentPlayerTurn->action_points >= intface.spell->cost && currentPlayerTurn->action_points > 0)
					{
						ref->castSpell(intface.spell, map.effectArea);
						intface.update_CurrentPlayer_ActionPoints();
					}
					released = true;
				}
			}
			
			// To Move when Right Click
			if (event.mouse.isButtonPressed(sf::Mouse::Button::Right) && tmp != NULL)
			{
				if (ref->checkMove(tmp) == true && ref->distance(&currentPlayerTurn->pos, tmp) == 1)
				{
					map.getCase(currentPlayerTurn->pos.x, currentPlayerTurn->pos.y)->unit = NULL;
					//map.map[std::make_pair(currentPlayerTurn->pos.x, currentPlayerTurn->pos.y)]->unit = NULL;
					//map.map[std::make_pair(tmp->x, tmp->y)]->unit = currentPlayerTurn;
					map.getCase(tmp->x, tmp->y)->unit = currentPlayerTurn;
					currentPlayerTurn->pos.x = tmp->x;
					currentPlayerTurn->pos.y = tmp->y;
					currentPlayerTurn->move_points -= 1;
					intface.update_HoverPlayer();
					intface.update_CurrentPlayer_MovementsPoints();
				}
			}
			

			graphic.drawMap(sf::Color(70, 46, 28, 255), tmp);
			intface.draw();
			graphic.drawTextEffect();

			// doit etre dans graphic (team dans graphic est pas bien set)
			for (int i = 0; i < teams.size(); ++i)
			{
				for (int j = 0; j < teams[i]->units.size(); ++j)
				{
					//teams[i]->units[j]->pos.x = 2 + (j * 3);
					//teams[i]->units[j]->pos.y = 1 + (i * 9);
					//std::cout <<"team unit vie :" << teams[i]->units[j]->life << std::endl;
					if (teams[i]->units[j]->isAlive == true)
					{
						setPlayerOnMap(teams[i]->units[j]);
						graphic.loadUnit(teams[i]->units[j]);
					}
				}
			}
			graphic.display();

			if (ref->gameOver() == true)
			{
				state = MENU;
				return;
			}
			//////////
		}
	}
}

// After Character Selection
void GameEngine::setPlayerOnMap(Unit *u)
{
	this->map.map[std::make_pair(u->pos.x, u->pos.y)]->unit = u;
}

void GameEngine::selectFirstPlayer()
{
	// Faire tri a bulle pour ordonner les units par initiative
	//BubbleSortUnitsInitiative(teams[0]->units);
	//BubbleSortUnitsInitiative(teams[1]->units);

	// Calcul initiative team
	for (unsigned int i = 0; i < teams.size(); ++i)
	{
		for (unsigned int j = 0; j < teams[i]->units.size(); ++j)
		{
			teams[i]->initiative += teams[i]->units[j]->initiative;
		}
	}

	if (teams[1]->initiative > teams[0]->initiative)
		teams[0]->units.swap(teams[1]->units);
	currentPlayerTurn = teams[0]->units[0];
	teams[0]->units[0]->isPlaying = true;
}

Pos *GameEngine::getMouseCoordinateOnMap()
{
	int posX = (event.mouse.getPosition(window).x - 10) / Settings::CASE_SIZE;
	int posY = (event.mouse.getPosition(window).y - 10) / Settings::CASE_SIZE;
	if (posX < Settings::MAP_WIDTH && posY < Settings::MAP_HEIGHT &&
		event.mouse.getPosition(window).x >= (Settings::CASE_SIZE) * posX + 9 &&
		event.mouse.getPosition(window).x <= (Settings::CASE_SIZE) * (posX + 1) + 4 &&
		event.mouse.getPosition(window).y >= (Settings::CASE_SIZE) * posY + 9 &&
		event.mouse.getPosition(window).y <= (Settings::CASE_SIZE) * (posY + 1) + 4)
	{
		return (new Pos(posX, posY));
	}
	return (NULL);
}

void GameEngine::createTimeLine()
{
	timeLine.push_back(teams[0]->units[0]);
	timeLine.push_back(teams[1]->units[0]);
	timeLine.push_back(teams[0]->units[1]);
	timeLine.push_back(teams[1]->units[1]);
	timeLine.push_back(teams[0]->units[2]);
	timeLine.push_back(teams[1]->units[2]);
}

//spell pas besoin de confirmation
//move click gauche dans la range de PM sur map
//click droit description sur map
// cancel
//bouton endTurn
// state currentState
/// while (stateMachine(click,&currentState) != endturn)
//  {
//    ????
//  }

//have to recheck and  complete that algo see with Axel what he will returns to me

/*
void GameEngine::playerTurn()
{
	while (!endOfTurn)
	{
	
	tmp = getMousePosition();
	if (state == neutral) {
		 if (whereDidIClick(tmp) == Map)
		{
			if (click == right)
				showDescription(tmp.x,tmp.y);
		}
		else if (whereDidIClick(tmp) == Spell) // doit aussi verifier que le spell est lan�able (PP) --> Referee
		{ 
		s = getSpell(tmp);
		state = spell;
		}
		else if (whereDidIClick(tmp) == endturn)
		{
		endturn = true;
		}
		else if (whereDidIclidk(tmp) == move) // doit aussi verifier que le mouvement est possible ---> Referee
		{
			state == move
		}
	}
	else if ( state == spell) 
	{
		showMapSpell(tmp);
		if (whereDidIclick == cancel) // Bouton cancel ??
		{
			state = neutral;
		}
		else if (whereDidIClick == map) // doit checker si la position du spell est bonne --> Referee
		{
			affFixeNapeSpell(tmp,s);
			validateS = tmp;
			state = validateSpell;
		}
	}
	else if (state == validateSpell)
	{
		affFixeNapeSpell(tmp,s);
		if (whereDidIclick == valid) //Bouton valide ??
		{
			castSpell(validate,s);
			state = neutral;
		}
		else if (wheredidIClick == cancel) // Bouton cancel ??
		{
			state = neutral;
		}
	}
	else if (state == move) 
	{
		if (whereDidIclick = p_move) // doit checker si la position du mouvement est bonne --> Referee
		{
			move
			state = neutral;
		}
		else if (wheredidIClick == cancel) // bouton cancel. ??
		{
			state = neutral;
		}

	}
}

/*** Player Turn ***/
// Mettre currentPlayerTurn (CPT) sur le joueur
// Envoyer CPT � l'interface
// Si souris passe sur la map, highlight la case cibl�e
// Si Case selectionn�e refresh interface; Si Spell selectionn� refresh map avec nappe range
// Si Case selectionn�e sur nappe de Spell lancer l'effet
// Si passer son tour selectionn�, changer CPT
// =D

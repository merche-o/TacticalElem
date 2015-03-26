#include "GameEngine.h"


GameEngine::GameEngine(void)
	: ressources(),
	menu(window, event, restart),
	sound(),
	map(),
	graphic(window, map, ressources),
	event(window)
{
	state = MENU;

	sound.musicOFF();
	sound.playMusic(sound.music);

	window.create(sf::VideoMode(Settings::WIDTH, Settings::HEIGHT, Settings::CASE_SIZE), Settings::GAME_NAME);
	window.setFramerateLimit(30);

	restart = false;

	// For Testing Only
	teams.push_back(new Team());
	teams.push_back(new Team());

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			teams[j]->units.push_back(new Unit(0, 0, i));
		}
	}
	//
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
				
				// Initialize
				restart = false;
			}

			
			// Au tout debut du tour d'un pion, retirer 1 tour d'effet (case/zone/buff/debuff) a son nom sur la map


			// Action Functions
			event.checkEvent();
			Pos *tmp = getMouseCoordinateOnMap();
			//////////
			
			// Display Functions
			window.clear();

			map.showEffectArea(5, 5, 5, false);
			graphic.drawMap(sf::Color(70, 46, 28, 255), tmp);	

			graphic.display();
			//////////
		}
	}
}

// After Character Selection
void GameEngine::selectFirstPlayer()
{
	// Faire tri a bulle pour ordonner les units par initiative
	BubbleSortUnitsInitiative(teams[0]->units);
	BubbleSortUnitsInitiative(teams[1]->units);

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
}

void GameEngine::changeCPT()
{
	int CPT_team = currentPlayerTurn->team_number;
	int CPT_num = currentPlayerTurn->player_number;
	
	if (CPT_team == 0)
		currentPlayerTurn = teams[1]->units[currentPlayerTurn->player_number];
	else
	{
		if (CPT_num == 2) // Max team's players
			CPT_num = -1;
		currentPlayerTurn = teams[0]->units[CPT_num + 1];
	}
}

Pos *GameEngine::getMouseCoordinateOnMap()
{
	if (this->map.map[std::make_pair(event.mouse.getPosition(window).x / Settings::CASE_SIZE, 
									event.mouse.getPosition(window).y / Settings::CASE_SIZE)])
		return (new Pos(event.mouse.getPosition(window).x / Settings::CASE_SIZE, 
						event.mouse.getPosition(window).y / Settings::CASE_SIZE));
	return (NULL);
}

/*** Player Turn ***/
// Mettre currentPlayerTurn (CPT) sur le joueur
// Envoyer CPT à l'interface
// Si souris passe sur la map, highlight la case ciblée
// Si Case selectionnée refresh interface; Si Spell selectionné refresh map avec nappe range
// Si Case selectionnée sur nappe de Spell lancer l'effet
// Si passer son tour selectionné, changer CPT
// =D
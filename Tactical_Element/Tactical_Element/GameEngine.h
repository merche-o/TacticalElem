#pragma once

#include <vector>
#include "SFML\Graphics.hpp"
#include "Settings.h"
#include "Ressources.h"
#include "Graphic.h"
#include "GameMenu.h"
#include "SoundEngine.h"
#include "Interface.h"
#include "Map.h"
#include "Event.h"
#include "Team.h"
#include "Utils.h"
#include "CharacterFactory.h"

class GameEngine
{
	enum e_state
	{
		MENU,
		GAME
	};

	//gère les etats possible de jeux du joueur
	enum p_state
	{
		NEUTRAL,
		SPELL,
		V_SPELL
		//MOVE ?
	};

private:
	e_state state;
	p_state playerState;
	Ressources ressources;
	Graphic graphic;
	GameMenu menu;
	SoundEngine sound;
	Map map;
	CharacterFactory factoryUnit;
	Interface intface;
	Event event;
	std::vector<Team*> teams;
	Unit* currentPlayerTurn;
	bool restart;

	Pos *getMouseCoordinateOnMap();
	void playerTurn();
public:
	sf::RenderWindow window;

public:
	GameEngine(void);
	~GameEngine(void);

	void run();
	void selectFirstPlayer();
	void changeCPT();
};


#pragma once

#include <vector>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Ressources.h"
#include "Graphic.h"
#include "GameMenu.h"
#include "SoundEngine.h"
#include "Interface.h"
#include "Event.h"
#include "Utils.h"
#include "CharacterFactory.h"
#include "Referee.h"

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
	Graphic graphic;
	GameMenu menu;
	SoundEngine sound;
	Map map;
	Referee *ref;
	Ressources ressources;
	CharacterFactory factoryUnit;
	Interface intface;
	Event event;
	std::vector<Team*> teams;
	std::vector<Unit*> timeLine;
	Unit* currentPlayerTurn;
	bool restart;
	bool released;

	Pos *getMouseCoordinateOnMap();
	void playerTurn();
public:
	sf::RenderWindow window;

public:
	GameEngine(void);
	~GameEngine(void);

	void run();
	void selectFirstPlayer();
	void setPlayerOnMap(Unit *u);
	void createTimeLine();
};


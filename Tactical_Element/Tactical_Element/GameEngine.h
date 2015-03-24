#pragma once

#include <vector>
#include "SFML\Graphics.hpp"
#include "Settings.h"
#include "Ressources.h"
#include "Graphic.h"
#include "GameMenu.h"
#include "SoundEngine.h"
#include "Map.h"
#include "Event.h"
#include "Team.h"
#include "Utils.h"

class GameEngine
{
	enum e_state
	{
		MENU,
		GAME
	};

private:
	e_state state;
	Ressources ressources;
	Graphic graphic;
	GameMenu menu;
	SoundEngine sound;
	Map map;
	Event event;
	std::vector<Team*> teams;
	Unit* currentPlayerTurn;
	bool restart;

public:
	sf::RenderWindow window;

public:
	GameEngine(void);
	~GameEngine(void);

	void run();
	void selectFirstPlayer();
	void changeCPT();
};


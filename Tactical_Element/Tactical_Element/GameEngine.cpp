#include "GameEngine.h"


GameEngine::GameEngine(void)
	: ressources(),
		menu(window, event, restart),
		sound(),
		map(),
		intface(map),
		graphic(window, map, ressources, intface),
		event(window, intface)
{
	state = GAME;

	sound.musicOFF();
	sound.playMusic(sound.music);

	window.create(sf::VideoMode(Settings::WIDTH, Settings::HEIGHT, Settings::CASE_SIZE), Settings::GAME_NAME);
	window.setFramerateLimit(30);
	
	restart = false;
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

			
			window.clear();
			event.checkEvent();
			// Au tout debut du tour d'un pion, retirer 1 tour d'effet (case/zone/buff/debuff) a son nom sur la map

			// Action Functions
			intface.run();
			// Display Functions
			graphic.drawMap();
			graphic.drawInterface();
			graphic.RefreshWindow();
		}
	}
}
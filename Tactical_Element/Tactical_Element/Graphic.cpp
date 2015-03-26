#include "Graphic.h"


Graphic::Graphic(sf::RenderWindow & w, Map & m, Ressources & r, Interface & i)
	: Display(w), win(w), map(m), ress(r), intface(i)
{
}


Graphic::~Graphic(void)
{
}

void Graphic::drawMap()
{
	int x = 0;
	int y = 0;
	
	while (y < Settings::MAP_HEIGHT)
	{
		while (x <Settings::MAP_WIDTH)
		{
			//dois changer suivent l'effet sur la case;
			//this->map.map[std::make_pair(x,y)]->effect;

			if (this->map.map[std::make_pair(x,y)])
			{
			sf::RectangleShape r;
			r.setFillColor(sf::Color(255,255,255,255));
			r.setPosition((Settings::CASE_SIZE) * x + 10 , ( Settings::CASE_SIZE) * y + 10);
			r.setSize(sf::Vector2f(Settings::CASE_SIZE - 5 , Settings::CASE_SIZE - 5));
			win.draw(r);
			}
			x++;
		}
		x = 0;
		y++;
	}
	
}

void Graphic::drawInterface(void)
{
	sf::RectangleShape r;
	r.setFillColor(sf::Color(255, 0, 0, 255));
	r.setPosition(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, 0);
	r.setSize(sf::Vector2f(Settings::INTERFACE_RIGHT_WIDTH, Settings::HEIGHT));
	win.draw(r);
	r.setFillColor(sf::Color(0, 255, 0, 255));
	r.setPosition(0, Settings::HEIGHT - Settings::INTERFACE_BOTTOM_HEIGHT);
	r.setSize(sf::Vector2f(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH, Settings::INTERFACE_BOTTOM_HEIGHT));
	win.draw(r);
	loadText(Settings::WIDTH - Settings::INTERFACE_RIGHT_WIDTH + 10, 20, font, std::to_string(static_cast<long long>(intface.mousePos.x)) + " " +  std::to_string(static_cast<long long>(intface.mousePos.y)), 20, 0, 0, 0);
}

#include "Graphic.h"


Graphic::Graphic(sf::RenderWindow & w, Map & m, Ressources & r)
	: Display(w), win(w), map(m), ress(r)
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
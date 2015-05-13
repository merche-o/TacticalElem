#include "Graphic.h"


Graphic::Graphic(sf::RenderWindow & w, Map & m, Ressources & r, std::vector<Team*> & t)
	: Display(w), win(w), map(m), ress(r), teams(t)
{
}


Graphic::~Graphic(void)
{
}

void Graphic::drawMap(sf::Color c, Pos *mouse)
{
	sf::RectangleShape R;

	for (int y = 0; y < Settings::MAP_HEIGHT; ++y)
	{
		for (int x = 0; x < Settings::MAP_WIDTH; ++x)
		{
			// Dois changer coleur/sprite suivent les proprieter de la case;
			
			if (this->map.map[std::make_pair(x, y)])
			{
				if (this->map.effectArea[std::make_pair(x, y)] == true)
					R.setFillColor(sf::Color(200, 0, 0, 255));
				else	if (this->map.map[std::make_pair(x,y)]->effect)
					R.setFillColor(sf::Color(0,0,200));
				
				else
					R.setFillColor(c);

				if (mouse && mouse->x == x && mouse->y == y)
					R.setFillColor(sf::Color(255, 255, 255, 100));

				R.setPosition((Settings::CASE_SIZE) * x + 10 , ( Settings::CASE_SIZE) * y + 10);
				R.setSize(sf::Vector2f(Settings::CASE_SIZE - 5 , Settings::CASE_SIZE - 5));
				win.draw(R);
			}
		}
	}
}

void Graphic::drawUnits()
{
	for (int i = 0; i < teams.size(); ++i)
	{
		for (int j = 0; j < teams[i]->units.size(); ++j)
		{
			loadUnit(teams[i]->units[j]);
		}
	}

}

/*void Graphic::drawInterface(void)
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
}*/


void Graphic::display()
{
	win.display();
}

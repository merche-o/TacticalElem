#include "Graphic.h"


Graphic::Graphic(sf::RenderWindow & w, Map & m, Ressources & r)
	: Display(w), win(w), map(m), ress(r)
{
}


Graphic::~Graphic(void)
{
}

void Graphic::drawMap(sf::Color c, Pos *mouse)
{
	int x = 0;
	int y = 0;
	sf::RectangleShape R;

	while (y < Settings::MAP_HEIGHT) {
		while (x <Settings::MAP_WIDTH) {
			//dois changer coleur/sprite suivent les proprieter de la case;
			//this->map.map[std::make_pair(x,y)]->effect;
			if (this->map.map[std::make_pair(x,y)]) {		
				if (this->map.effectArea[std::make_pair(x,y)] == true)
					R.setFillColor(sf::Color(200,0,0,255));
				else
					R.setFillColor(c);
				if (mouse && mouse->x == x && mouse->y == y)
					R.setFillColor(sf::Color(255,255,255,100));
				R.setPosition((Settings::CASE_SIZE) * x + 10 , ( Settings::CASE_SIZE) * y + 10);
				R.setSize(sf::Vector2f(Settings::CASE_SIZE - 5 , Settings::CASE_SIZE - 5));
				win.draw(R);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void Graphic::display()
{
	win.display();
}
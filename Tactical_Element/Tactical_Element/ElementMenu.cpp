#include "ElementMenu.h"


ElementMenu::ElementMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)())
	: Display(w), pos(X, Y), state(s), p(ptr)
{
}


ElementMenu::~ElementMenu(void)
{
}

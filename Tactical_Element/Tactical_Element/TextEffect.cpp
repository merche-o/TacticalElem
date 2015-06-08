#include "TextEffect.h"


TextEffect::TextEffect(sf::RenderWindow & w, float X, float Y, std::string str, sf::Font & Font, int r, int g, int b)
	: Display(w), pos(X, Y), text(str), size(32), font(Font), color(r, g, b), time(10)
{
	effectText.setFont(font);

	effectText.setCharacterSize(size);
	effectText.setColor(sf::Color(r, g, b, 255));
	effectText.setPosition(X, Y);
	effectText.setString(str);
}


TextEffect::~TextEffect(void)
{
}

void TextEffect::draw()
{
	loadText(effectText);
	
	pos.y -= 5;
	effectText.setPosition(pos.x, pos.y);
	
	color.a = 55 + (time * 20);
	effectText.setColor(color);

	--time;
}

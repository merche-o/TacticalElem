#pragma once

#include <SFML\Graphics.hpp>
#include "Unit.h"
#include "ElementMenu.h"

class ImageMenu : public ElementMenu
{
public:
	//sf::Texture & texture;
	Unit * unit;
	sf::Sprite sprite;

public:
	ImageMenu(sf::RenderWindow & w, float X, float Y, e_state s, void(GameMenu:: *ptr)(),  Unit * u);
	~ImageMenu(void);

	virtual void draw();
	virtual void lightDraw();
	virtual sf::FloatRect getBounds();
	virtual Unit * getUnitSelected();
	virtual std::string getStringText() {return (std::string(""));};
};


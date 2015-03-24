#include "Map.h"


Map::Map(void)
{
	h = Settings::MAP_HEIGHT;
	w = Settings::MAP_WIDTH; 
	this->createMap();
}


Map::~Map(void)
{
}

void Map::showEffectArea(int x, int y, int lenght, bool center)
{
	int x1 = x - lenght;
	int y1 = y - lenght;
	int save_x;

	if (x1 < 0)
		x1 = 0;
	if (y1 < 0)
		y1 = 0;
	save_x = x1;
	while (y1 <= y + lenght)
	{
	
		while (x1 <= x + lenght)
		{
			if ((y1 - y) + (x1 - x) <= lenght 
				&& (y1 - y) + (x1 - x) >= -lenght
				&& (y1+y) - (x1 +x) <= lenght
				&& (y1+y) - (x1 + x) >= - lenght )
			{	
				
				if (x1 == x && y1 == y && center == false)
					this->effectArea[std::make_pair(x1,y1)] = false;
				else
					this->effectArea[std::make_pair(x1,y1)] = true;
				
			}
				//alterate map color
			//	this->map[std::make_pair(x1,y1)]
			x1++;
		}
		x1 = save_x;
		y1++;
	}

}

void Map::createMap()
{
	int x = 0;
	int y = 0;

	while (y < h)
	{
		while (x < w)
		{
			this->map[std::make_pair(x,y)] = new Case();		
			x++;
		}
		x = 0;
		y++;
	}
}

Case const *Map::getCase(int x, int y)
{
	return this->map[std::make_pair(x,y)];
}

//peu changer

bool Map::putEffectOnCase(Effect *e, int x, int y)
{
	if (this->map[std::make_pair(x,y)]->effect == NULL) 
		this->map[std::make_pair(x,y)]->effect = e;
	return (false);
}
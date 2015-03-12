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
}
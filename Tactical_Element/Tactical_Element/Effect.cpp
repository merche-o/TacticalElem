#include "Effect.h"


Effect::Effect(void)
	: teleport(-1, -1), displace(0, 0), isWall(false)
{
	duration = 0;
	life = 0;
	move_points = 0;
	action_points = 0;
}

Effect::~Effect(void)
{
}

void Effect::setLife(int i)
{
	life = i;
}

void Effect::setDuration(int i)
{
	duration = i;
}

void Effect::setMovePoints(int i)
{
	move_points = i;
}

void Effect::setActionPoints(int i)
{
	action_points = i;
}

void Effect::setTeleport(Pos p)
{
	teleport = p;
}

void Effect::setDisplace(Pos p)
{
	displace = p;
}

void Effect::setWall(bool b)
{
	isWall = b;
}
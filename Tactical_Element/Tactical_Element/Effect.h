#pragma once

#include "Pos.h"

class Effect
{
public:
	int duration;
	int life; // Degats / Soins
	int move_points; // Ajout ou Retrait de PM
	int action_points; // Ajout ou Retrait de PA
	Pos teleport; // Teleportation
	Pos displace; // Bouger la cible 
	bool isWall; // Pour creation de murs

public:
	Effect(void);
	~Effect(void);

	void setMovePoints(int i);
	void setActionPoints(int i);
	void setTeleport(Pos p);
	void setDisplace(Pos p);
	void setWall(bool b);
	void setDuration(int i);
	void setLife(int i);
};


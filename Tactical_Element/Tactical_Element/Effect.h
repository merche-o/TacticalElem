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

public:
	Effect(void);
	~Effect(void);
};


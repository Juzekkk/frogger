#pragma once
#include "plane.h"
#include "logEntity.h"

class RiverPlane : public Plane
{
public:
	RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};


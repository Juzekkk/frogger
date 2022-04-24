#pragma once
#include "plane.h"
#include "carEntity.h"
class RoadPlane : public Plane
{
public:
	RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};


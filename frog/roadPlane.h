#pragma once
#include "plane.h"
#include "carEntity.h"
#include "spriteDispenser.h"

class RoadPlane : public Plane
{
public:
	RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};


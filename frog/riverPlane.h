#pragma once
#include "plane.h"
#include "logEntity.h"
#include "spriteDispenser.h"

class RiverPlane : public Plane
{
public:
	RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	bool frogOnRiver(sf::RenderWindow& window, Frog& frog);
	bool frogOnLog(sf::RenderWindow& window, Frog& frog);
};
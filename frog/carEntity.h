#pragma once
#include "movingEntity.h"
#include "spriteDispenser.h"
class CarEntity : public MovingEntity
{
public:
	CarEntity (sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};
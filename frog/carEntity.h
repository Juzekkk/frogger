#pragma once
#include "movingEntity.h"
class CarEntity : public MovingEntity
{
public:
	CarEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	void move(const int globalTickrate, sf::RenderWindow& window, Frog& frog);
};


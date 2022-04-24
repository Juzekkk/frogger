#pragma once
#include "movingEntity.h"
class LogEntity : public MovingEntity
{
public:
	LogEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	void move(const int globalTickrate, sf::RenderWindow& window, Frog& frog);
};


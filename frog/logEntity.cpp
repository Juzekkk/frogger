#include "logEntity.h"

LogEntity::LogEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) 
	: MovingEntity(size, right, globalTickrate, startingPosition)
{
	// Sprite
	sprite.setTexture(*SpriteDispenser::getTexturePoiner("log"));
	sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
	sprite.setPosition(shape.getPosition());
}

void LogEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	if (tickrate)
		tickrate--;
	else {
		bool frogOnLog = frogOnObject(window, frog);
		if (isRight) {
			if (frogOnLog)
				frog.getShape().move(shape.getSize().y, 0);
			shape.move(shape.getSize().y, 0);
		}
		else {
			if (frogOnLog)
				frog.getShape().move(-shape.getSize().y, 0);
			shape.move(-shape.getSize().y, 0);
		}
		tickrate = globalTickrate;
	}
}

void LogEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	move(window, globalTickrate, frog);
}
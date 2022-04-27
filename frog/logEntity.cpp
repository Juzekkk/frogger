#include "logEntity.h"

LogEntity::LogEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) 
	: MovingEntity(size, right, globalTickrate, startingPosition)
{

	graphic.setTexture(*SpriteDispenser::getTexturePoiner("log"));
	reloadTexture();
}

void LogEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	move(window, globalTickrate, frog);
}

void LogEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	if (tickrate)
		tickrate--;
	else {
		tickrate = globalTickrate;
		bool frogOnLog = frogOnObject(window, frog);
		if (isRight) {
			sf::Vector2f moveVector(hitbox.getSize().y, 0);
			if (frogOnLog)
				frog.move(moveVector);
			hitbox.move(moveVector);
		}
		else {
			sf::Vector2f moveVector(-hitbox.getSize().y, 0);
			if (frogOnLog)
				frog.move(moveVector);
			hitbox.move(moveVector);
		}
	}
}
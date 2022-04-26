#include "carEntity.h"

CarEntity::CarEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) :
	MovingEntity(size, right, globalTickrate, startingPosition) {
	// Sprite
	int roll = rand() % 3;
	if (roll == 0)
		sprite.setTexture(*SpriteDispenser::getTexturePoiner("car"));
	else if (roll == 1)
		sprite.setTexture(*SpriteDispenser::getTexturePoiner("carBlue"));
	else
		sprite.setTexture(*SpriteDispenser::getTexturePoiner("carRed"));
	sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
}

void CarEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	if (tickrate)
		tickrate--;
	else {
		// Car movement
		if (isRight) {
			shape.move(shape.getSize().y, 0);
		}
		else {
			shape.move(-shape.getSize().y, 0);
		}
		// Tickrate reset
		tickrate = globalTickrate;
	}
}

void CarEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	if (frogOnObject(window, frog)) {
		frog.die(window);
	}
	move(window, globalTickrate, frog);
}
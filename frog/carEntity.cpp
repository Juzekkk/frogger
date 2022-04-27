#include "carEntity.h"

CarEntity::CarEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) :
	MovingEntity(size, right, globalTickrate, startingPosition) {

	int roll = rand() % 3;
	if (roll == 0)
		graphic.setTexture(*SpriteDispenser::getTexturePoiner("car"));
	else if (roll == 1)
		graphic.setTexture(*SpriteDispenser::getTexturePoiner("carBlue"));
	else
		graphic.setTexture(*SpriteDispenser::getTexturePoiner("carRed"));
	reloadTexture();
}

void CarEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {

	if (frogOnObject(window, frog)) {
		frog.die(window);
	}
	move(window, globalTickrate, frog);
}

void CarEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {

	if (tickrate)
		tickrate--;
	else {
		tickrate = globalTickrate;
		if (isRight) {
			hitbox.move(hitbox.getSize().y, 0);
		}
		else {
			hitbox.move(-hitbox.getSize().y, 0);
		}
	}
}
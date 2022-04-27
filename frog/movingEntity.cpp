#include "movingEntity.h"

MovingEntity::MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition)
{

	tickrate = globalTickrate;
	isRight = right;

	hitbox.setSize(size);
	hitbox.setPosition(startingPosition);
}

bool MovingEntity::frogOnObject(sf::RenderWindow& window, Frog& frog) {

	if (frog.getHitbox().getPosition().y != hitbox.getPosition().y)
		return false;
	return hitbox.getGlobalBounds().intersects(frog.getHitbox().getGlobalBounds());
}

void MovingEntity::reloadTexture() {

	graphic.setTextureRect(sf::IntRect(hitbox.getPosition().x, hitbox.getPosition().y, hitbox.getSize().x, hitbox.getSize().y));
}

sf::RectangleShape& MovingEntity::getHitbox() {

	return hitbox;
}

void MovingEntity::draw(sf::RenderWindow& window) {

	graphic.setPosition(hitbox.getPosition());
	window.draw(graphic);
}


void MovingEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

void MovingEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}
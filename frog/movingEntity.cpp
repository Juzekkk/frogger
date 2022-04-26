#include "movingEntity.h"

MovingEntity::MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition)
{
	tickrate = globalTickrate;
	isRight = right;
	// Hitbox
	shape.setSize(size);
	shape.setPosition(startingPosition);
}

void MovingEntity::draw(sf::RenderWindow& window) {
	sprite.setPosition(shape.getPosition());
	window.draw(sprite);
}

sf::RectangleShape& MovingEntity::getShape() {
	return shape;
}

void MovingEntity::move(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

bool MovingEntity::frogOnObject(sf::RenderWindow& window, Frog& frog) {
	return (shape.getGlobalBounds().contains(
		frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
		frog.getShape().getPosition().y + frog.getShape().getSize().y / 2));
}

void MovingEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}
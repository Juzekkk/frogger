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
	if (frog.getShape().getPosition().y != shape.getPosition().y)
		return false;
	return shape.getGlobalBounds().intersects(frog.getShape().getGlobalBounds());
	
}

void MovingEntity::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

void MovingEntity::resizeTexture() {
	sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
}
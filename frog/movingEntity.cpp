#include "movingEntity.h"

MovingEntity::MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition)
{
	tickrate = globalTickrate;
	isRight = right;
	shape.setSize(size);
	shape.setPosition(startingPosition);
}

void MovingEntity::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::RectangleShape& MovingEntity::getShape() {
	return shape;
}

void MovingEntity::move(const int globalTickrate, sf::RenderWindow& window, Frog& frog) {
	;
}
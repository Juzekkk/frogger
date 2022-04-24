#include "carEntity.h"

CarEntity::CarEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) :
	MovingEntity(size, right, globalTickrate, startingPosition) 
{
	shape.setFillColor(sf::Color(92, 0, 0));
}

void CarEntity::move(const int globalTickrate, sf::RenderWindow& window, Frog& frog) {
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
		// Collision check
		if (shape.getGlobalBounds().contains(
			frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
			frog.getShape().getPosition().y + frog.getShape().getSize().y / 2)) 
		{
			frog.getShape().setPosition(0, window.getSize().y - frog.getShape().getSize().y);
		}
		// Tickrate reset
		tickrate = globalTickrate;
	}
}
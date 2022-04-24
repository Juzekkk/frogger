#include "logEntity.h"

LogEntity::LogEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) :
	MovingEntity(size, right, globalTickrate, startingPosition) {
	shape.setFillColor(sf::Color(132, 83, 50));
}

void LogEntity::move(const int globalTickrate, sf::RenderWindow& window, Frog& frog) {
	if (tickrate)
		tickrate--;
	else {
		if (isRight) {
			// Move frog if frog on log
			if (shape.getGlobalBounds().contains(
				frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
				frog.getShape().getPosition().y + frog.getShape().getSize().y / 2))
			{
				frog.getShape().move(40, 0);
			}
			// Move log
			shape.move(shape.getSize().y, 0);
		}
		else {
			// Move frog if frog on log
			if (shape.getGlobalBounds().contains(
				frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
				frog.getShape().getPosition().y + frog.getShape().getSize().y / 2))
			{
				frog.getShape().move(-40, 0);
			}
			// Move log
			shape.move(-shape.getSize().y, 0);
		}
		// Reset tickrate
		tickrate = globalTickrate;
	}
}
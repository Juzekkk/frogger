#include "plane.h"

Plane::Plane(sf::RenderWindow& window, bool right, int startingPosition) {
	isRight = right;
	shape.setSize(sf::Vector2f(window.getSize().x + 6 * 40, 40));
	shape.setPosition(sf::Vector2f(-3 * 40, startingPosition * 40));
}

void Plane::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	for (auto& x : movingEntities)
		x->draw(window);
}

sf::RectangleShape& Plane::getShape() {
	return shape;
}

void Plane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

std::vector<MovingEntity*> Plane::getElements() {
	return movingEntities;
}

void Plane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}
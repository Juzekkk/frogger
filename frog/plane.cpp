#include "plane.h"

Plane::Plane(sf::RenderWindow& window, bool right, int startingPosition) {
	isRight = right;
	shape.setSize(sf::Vector2f(window.getSize().x + 6 * 40, 40));
	shape.setPosition(sf::Vector2f(-3 * 40, startingPosition * 40));
}

void Plane::draw(sf::RenderWindow& window) {
	// Draw plane itself
	window.draw(shape);
	// Draw every moving object on plane
	for (auto& x : movingEntities)
		x->draw(window);
}

sf::RectangleShape& Plane::getShape() {
	return shape;
}

void Plane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog){}

std::vector<MovingEntity*> Plane::getElements() {
	return movingEntities;
}

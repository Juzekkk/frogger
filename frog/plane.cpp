#include "plane.h"

Plane::Plane(sf::RenderWindow& window, bool right, int startingPosition) {

	isRight = right;
	hitbox.setSize(sf::Vector2f(window.getSize().x + 6 * 40, 40));
	hitbox.setPosition(sf::Vector2f(-3 * 40, startingPosition * 40));
}

sf::RectangleShape& Plane::getHitbox() {

	return hitbox;
}

void Plane::draw(sf::RenderWindow& window) {

	window.draw(graphic);
	for (auto& x : movingEntities)
		x->draw(window);
}

void Plane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

void Plane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {}

std::vector<MovingEntity*> Plane::getElements() {

	return movingEntities;
}
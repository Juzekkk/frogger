#include "roadPlane.h"

RoadPlane::RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate) :
	Plane(window, right, startingPosition) {

	// Set plane color
	sprite.setTexture(*SpriteDispenser::getTexturePoiner("road"));
	sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
	sprite.setPosition(shape.getPosition());
	// Spawn cars
	int i = 0;
	while (i < shape.getSize().x) {
		CarEntity* temp = new CarEntity(sf::Vector2f(40 * (rand() % 2 + 2), 40),
			right, globalTickrate, sf::Vector2f(i, shape.getPosition().y));
		movingEntities.push_back(temp);
		i += temp->getShape().getSize().x + ((rand() % 2 + 1) * 40);
	}
}

void RoadPlane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	moveElements(window, globalTickrate, frog);
}

void RoadPlane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : movingEntities) {
		// Move car
		x->performTick(window, globalTickrate, frog);
		// If element flew away -> reset element position and reroll its size
		if (x->getShape().getPosition().x > shape.getSize().x) {
			// Size reroll
			x->getShape().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			// Reposition
			x->getShape().setPosition(shape.getPosition());
		}
		else if (x->getShape().getPosition().x < shape.getPosition().x) {
			// Size reroll
			x->getShape().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			// Reposition
			x->getShape().setPosition(shape.getSize().x, shape.getPosition().y);
		}
	}
}
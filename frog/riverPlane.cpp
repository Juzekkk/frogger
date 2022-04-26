#include "riverPlane.h"

RiverPlane::RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate) :
	Plane(window, right, startingPosition) {
	// Sprite
	sprite.setTexture(*SpriteDispenser::getTexturePoiner("water"));
	sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
	sprite.setPosition(shape.getPosition());
	// Spawn logs
	int i = 0;
	while (i < shape.getSize().x) {
		LogEntity* temp = new LogEntity(sf::Vector2f(40 * (rand() % 2 + 2), 40), 
			right, globalTickrate, sf::Vector2f(i, shape.getPosition().y));
		movingEntities.push_back(temp);
		i += temp->getShape().getSize().x + ((rand() % 2 + 1) * 40);
	}
}

void RiverPlane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	if (frogOnRiver(window, frog) && !frogOnLog(window, frog))
		frog.die(window);
	moveElements(window, globalTickrate, frog);
}

bool RiverPlane::frogOnRiver(sf::RenderWindow& window, Frog& frog) {
	return (shape.getGlobalBounds().contains(
		frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
		frog.getShape().getPosition().y + frog.getShape().getSize().y / 2));
}

bool RiverPlane::frogOnLog(sf::RenderWindow& window, Frog& frog) {
	bool frogOnLog = false;
	for (auto& log : movingEntities) {
		if (log->frogOnObject(window, frog))
			frogOnLog = true;
	}
	return frogOnLog;
}

void RiverPlane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : movingEntities) {
		x->performTick(window, globalTickrate, frog);
		if (x->getShape().getPosition().x > shape.getSize().x) {
			x->getShape().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			x->getShape().setPosition(shape.getPosition());
		}
		else if (x->getShape().getPosition().x < shape.getPosition().x) {
			x->getShape().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			x->getShape().setPosition(shape.getSize().x, shape.getPosition().y);
		}
	}
}
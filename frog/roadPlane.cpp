#include "roadPlane.h"

RoadPlane::RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate) :
	Plane(window, right, startingPosition) {

	graphic.setTexture(*SpriteDispenser::getTexturePoiner("road"));
	graphic.setTextureRect(sf::IntRect(hitbox.getPosition().x, hitbox.getPosition().y, hitbox.getSize().x, hitbox.getSize().y));
	graphic.setPosition(hitbox.getPosition());

	int i = 0;
	while (i < hitbox.getSize().x) {
		CarEntity* temp = new CarEntity(sf::Vector2f(40 * (rand() % 2 + 2), 40),
			right, globalTickrate, sf::Vector2f(i, hitbox.getPosition().y));
		movingEntities.push_back(temp);
		i += temp->getHitbox().getSize().x + ((rand() % 2 + 1) * 40);
	}
}

void RoadPlane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	moveElements(window, globalTickrate, frog);
}

void RoadPlane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : movingEntities) {
		// Move car
		x->performTick(window, globalTickrate, frog);
		if (x->getHitbox().getPosition().x > hitbox.getSize().x) {
			x->getHitbox().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			x->getHitbox().setPosition(hitbox.getPosition());
			x->reloadTexture();
		}
		else if (x->getHitbox().getPosition().x < hitbox.getPosition().x) {
			x->getHitbox().setSize(sf::Vector2f((rand() % 3 + 1) * 40, 40));
			x->getHitbox().setPosition(hitbox.getSize().x, hitbox.getPosition().y);
			x->reloadTexture();
		}
	}
}
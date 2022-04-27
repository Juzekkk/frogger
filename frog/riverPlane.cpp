#include "riverPlane.h"

RiverPlane::RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate) :
	Plane(window, right, startingPosition) {

	graphic.setTexture(*SpriteDispenser::getTexturePoiner("water"));
	graphic.setTextureRect(sf::IntRect(hitbox.getPosition().x, hitbox.getPosition().y, hitbox.getSize().x, hitbox.getSize().y));
	graphic.setPosition(hitbox.getPosition());

	int i = 0;
	while (i < hitbox.getSize().x) {
		LogEntity* temp = new LogEntity(sf::Vector2f(40 * (rand() % 2 + 2), 40), 
			right, globalTickrate, sf::Vector2f(i, hitbox.getPosition().y));
		movingEntities.push_back(temp);
		i += temp->getHitbox().getSize().x + ((rand() % 2 + 1) * 40);
	}
}

void RiverPlane::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {

	moveElements(window, globalTickrate, frog);
	if (frogOnRiver(window, frog) && !frogOnLog(window, frog))
		frog.die(window);
}

void RiverPlane::moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : movingEntities) {
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

bool RiverPlane::frogOnRiver(sf::RenderWindow& window, Frog& frog) {
	if (frog.getHitbox().getPosition().y != hitbox.getPosition().y)
		return false;
	else
		return (hitbox.getGlobalBounds().intersects(frog.getHitbox().getGlobalBounds()));
}

bool RiverPlane::frogOnLog(sf::RenderWindow& window, Frog& frog) {
	bool frogOnLog = false;
	for (auto& log : movingEntities) {
		if (log->frogOnObject(window, frog))
			frogOnLog = true;
	}
	return frogOnLog;
}
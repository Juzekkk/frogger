#include "riverPlane.h"

RiverPlane::RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate) :
	Plane(window, right, startingPosition) {

	// Set planes color
	shape.setFillColor(sf::Color(121, 163, 255));
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
	
	// If frog on river
	if (shape.getGlobalBounds().contains(
	frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
	frog.getShape().getPosition().y + frog.getShape().getSize().y / 2)) 
	{
		// If frog on log -> dont kill it
		bool killHim = true;
		for (auto& log : movingEntities) {
			if (log->getShape().getGlobalBounds().contains(
				frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
				frog.getShape().getPosition().y + frog.getShape().getSize().y / 2))
			{
				killHim = false;
			}
		}
		// If frog not on log -> kill it
		if (killHim)
			frog.getShape().setPosition(0, window.getSize().y - frog.getShape().getSize().y);
	}
	
	// Flow of elements
	for (auto& x : movingEntities) {
		// Move every element
		x->move(globalTickrate, window, frog);
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
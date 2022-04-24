#pragma once
#include <SFML/Graphics.hpp>
#include "movingEntity.h"
#include "frog.h"

class Plane
{
public:
	Plane(sf::RenderWindow& window, bool right, int positionY);
	void draw(sf::RenderWindow& window);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	sf::RectangleShape& getShape();
	std::vector<MovingEntity*> getElements();

protected:
	std::vector<MovingEntity*> movingEntities;
	sf::RectangleShape shape;
	bool isRight;
};
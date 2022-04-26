#pragma once
#include <SFML/Graphics.hpp>
#include "movingEntity.h"
#include "frog.h"
#include <iostream>

class Plane
{
public:
	Plane(sf::RenderWindow& window, bool right, int positionY);
	void draw(sf::RenderWindow& window);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	sf::RectangleShape& getShape();

protected:
	std::vector<MovingEntity*> getElements();
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	std::vector<MovingEntity*> movingEntities;
	sf::RectangleShape shape;
	sf::Sprite sprite;
	bool isRight;
};
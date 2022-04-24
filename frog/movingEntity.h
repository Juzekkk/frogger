#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"
class MovingEntity
{
public:
	MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	void draw(sf::RenderWindow& window);
	virtual void move(const int globalTickrate, sf::RenderWindow& window, Frog& frog);
	sf::RectangleShape& getShape();

protected:
	sf::RectangleShape shape;
	bool isRight;
	int tickrate;
};

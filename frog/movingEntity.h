#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"
class MovingEntity
{
public:
	MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	void draw(sf::RenderWindow& window);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	bool frogOnObject(sf::RenderWindow& window, Frog& frog);
	sf::RectangleShape& getShape();

protected:
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	sf::RectangleShape shape;
	sf::Sprite sprite;
	bool isRight;
	int tickrate;
};

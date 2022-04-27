#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"

class MovingEntity
{
public:
	MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	bool frogOnObject(sf::RenderWindow& window, Frog& frog);
	void reloadTexture();
	sf::RectangleShape& getHitbox();
	void draw(sf::RenderWindow& window);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
protected:
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	bool isRight;
	int tickrate;
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};

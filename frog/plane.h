#pragma once
#include <SFML/Graphics.hpp>
#include "movingEntity.h"
#include "frog.h"
#include <iostream>

class Plane
{
public:
	Plane(sf::RenderWindow& window, bool right, int positionY);
	sf::RectangleShape& getHitbox();
	void draw(sf::RenderWindow& window);
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);

protected:
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	std::vector<MovingEntity*> getElements();
	bool isRight;
	std::vector<MovingEntity*> movingEntities;
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};
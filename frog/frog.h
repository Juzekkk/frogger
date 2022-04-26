#pragma once
#include <SFML/Graphics.hpp>
#include "spriteDispenser.h"
class Frog
{
public:
	Frog(sf::Vector2f windowSize);
	void draw(sf::RenderWindow& window);
	void move(sf::RenderWindow& window);
	void die(sf::RenderWindow& window);
	sf::RectangleShape& getShape();

private:
	sf::RectangleShape frog;
	sf::Sprite sprite;
};


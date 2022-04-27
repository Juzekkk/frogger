#pragma once
#include <SFML/Graphics.hpp>
#include "spriteDispenser.h"
class Frog
{
public:
	Frog(sf::Vector2f windowSize);
	void move(sf::RenderWindow& window);
	void move(sf::Vector2f vector);
	void die(sf::RenderWindow& window);
	sf::RectangleShape& getHitbox();
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};


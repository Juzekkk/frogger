#include "carEntity.h"

CarEntity::CarEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition) :
	MovingEntity(size, right, globalTickrate, startingPosition)
{
	shape.setFillColor(sf::Color(92, 0, 0));
	MovingEntity(size, right, globalTickrate, startingPosition) {
		// Sprite
		int roll = rand() % 3;
		if (roll == 0)
			sprite.setTexture(*SpriteDispenser::getTexturePoiner("car"));
		else if (roll == 1)
			sprite.setTexture(*SpriteDispenser::getTexturePoiner("carBlue"));
		else
			sprite.setTexture(*SpriteDispenser::getTexturePoiner("carRed"));
		sprite.setTextureRect(sf::IntRect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y));
	}

	void CarEntity::move(const int globalTickrate, sf::RenderWindow & window, Frog & frog) {
		void CarEntity::move(sf::RenderWindow & window, int globalTickrate, Frog & frog) {
			if (tickrate)
				tickrate--;
			else {
				@ - 17, 14 + 24, 14 @@ void CarEntity::move(const int globalTickrate, sf::RenderWindow & window, Frog & f
		else {
		shape.move(-shape.getSize().y, 0);
		}
		// Collision check
		if (shape.getGlobalBounds().contains(
			frog.getShape().getPosition().x + frog.getShape().getSize().x / 2,
			frog.getShape().getPosition().y + frog.getShape().getSize().y / 2))
		{
			frog.getShape().setPosition(0, window.getSize().y - frog.getShape().getSize().y);
		}
		// Tickrate reset
		tickrate = globalTickrate;
			}
		}

		void CarEntity::performTick(sf::RenderWindow & window, int globalTickrate, Frog & frog) {
			if (frogOnObject(window, frog)) {
				frog.die(window);
			}
			move(window, globalTickrate, frog);
		}
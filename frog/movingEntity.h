/**	@file movingEntity.h
 *	@brief Class of basic moving entity within game.
 *
 *	Class is made as a parent class of every moving entity.
 *	It is able to move, perform all nessesary boundry checks
 *	and draw its graphic representation onto window.
 *
 *	@author Micha³ Juœkiewicz
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"

class MovingEntity
{
public:
/** @brief Constructor of MovingEntity Class.
 *
 *  Constructor takes necessary parameters and create class instance accordingly.
 *
 *  @param size Vector of x and y size values.
 *	@param right Defines move orientation of the element.
 *	@param globalTickrate Game tickrate, nessesary for proper, synchronized movement.
 *	@param startingPosition Vector of x and y position values.
 *  @return MovingEntity Class Instance.
 */
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

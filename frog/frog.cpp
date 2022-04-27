# include "frog.h"

Frog::Frog(sf::Vector2f windowSize) {

	hitbox.setSize(sf::Vector2f(40, 40));
	hitbox.setPosition(sf::Vector2f(hitbox.getPosition().x, windowSize.y - hitbox.getSize().y));;

	graphic.setTexture(*SpriteDispenser::getTexturePoiner("frog"));
	graphic.setTextureRect(sf::IntRect(hitbox.getPosition().x, hitbox.getPosition().y, hitbox.getSize().x, hitbox.getSize().y));
}

void Frog::move(sf::RenderWindow& window) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && hitbox.getPosition().x >= hitbox.getSize().x)
		move(sf::Vector2f(-hitbox.getSize().x, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && hitbox.getPosition().x < window.getSize().x - hitbox.getSize().x)
		move(sf::Vector2f(hitbox.getSize().x, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && hitbox.getPosition().y >= hitbox.getSize().y)
		move(sf::Vector2f(0, -hitbox.getSize().y));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && hitbox.getPosition().y < window.getSize().y - hitbox.getSize().y)
		move(sf::Vector2f(0, +hitbox.getSize().y));
}

void Frog::move(sf::Vector2f vector) {

	hitbox.move(vector);
	graphic.setPosition(hitbox.getPosition());
}

void Frog::die(sf::RenderWindow& window) {

	hitbox.setPosition(0, window.getSize().y - hitbox.getSize().y);
}

sf::RectangleShape& Frog::getHitbox() {

	return hitbox;
}

void Frog::draw(sf::RenderWindow& window) {

	graphic.setPosition(hitbox.getPosition());
	window.draw(graphic);
}
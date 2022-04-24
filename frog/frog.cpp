# include "frog.h"

Frog::Frog(sf::Vector2f windowSize) {
	frog.setFillColor(sf::Color::Green);
	frog.setSize(sf::Vector2f(40, 40));
	frog.setPosition(sf::Vector2f(frog.getPosition().x, windowSize.y - frog.getSize().y));
}

void Frog::draw(sf::RenderWindow& window) {
	window.draw(frog);
}

sf::RectangleShape& Frog::getShape() {
	return frog;
}

void Frog::move(sf::RenderWindow& window) {
		// Arrow movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && frog.getPosition().x >= frog.getSize().x)
		frog.move(-frog.getSize().x, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && frog.getPosition().x < window.getSize().x - frog.getSize().x)
		frog.move(frog.getSize().x, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && frog.getPosition().y >= frog.getSize().y)
		frog.move(0, -frog.getSize().y);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && frog.getPosition().y < window.getSize().y - frog.getSize().y)
		frog.move(0, frog.getSize().y);
}
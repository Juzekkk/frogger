#include "game.h"


Game::Game(int windowWidth, int windowHeight, int tick_rate, int FPS) {
	srand((unsigned)time(0));
	tickrate = tick_rate;
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "frog");
	window->setFramerateLimit(FPS);

	frog = new Frog(sf::Vector2f(window->getSize().x, window->getSize().y));
	map = new Map(*window, tickrate, *frog);
}

void Game::run() {
	while (window->isOpen()) {
		sf::Event event;

		// Handle Input
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type = sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Key::Escape)
					window->close();
				else
					frog->move(*window);
			}
		}

		// Update the game

		// End Level
		if (frog->getShape().getPosition().y < frog->getShape().getSize().y) {
			frog->getShape().setPosition(sf::Vector2f(0, window->getSize().y - frog->getShape().getSize().y));
			tickrate -= 10;
			map->nextLevel(*window, tickrate, *frog);
		}

		//performTick
		map->performTick(*window, tickrate, *frog);

		// draw objects
		window->clear(sf::Color(10, 30, 0));
		map->draw(*window);
		frog->draw(*window);
		window->display();

	}
}
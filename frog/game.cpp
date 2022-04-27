#include "game.h"


Game::Game(int tick_rate, int FPS) {

	srand((unsigned)time(0));
	tickrate = tick_rate;

	window = new sf::RenderWindow(sf::VideoMode(720, 720), "frog");
	window->setFramerateLimit(FPS);

	frog = new Frog(sf::Vector2f(window->getSize().x, window->getSize().y));

	map = new Map(*window, tickrate, *frog);

	background.setTexture(*SpriteDispenser::getTexturePoiner("grass"));
	background.setTextureRect(sf::IntRect(0, 0, 720, 720));
}

void Game::run() {
	while (window->isOpen()) {
		
		sf::Event event;
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

		if (frogOnMeta()) {
			frog->die(*window);
			tickrate *= 0.9;
			map->nextLevel(*window, tickrate, *frog);
		}

		map->performTick(*window, tickrate, *frog);

		window->clear();

		window->draw(background);
		map->draw(*window);
		frog->draw(*window);

		window->display();
	}
}

bool Game::frogOnMeta() {
	return (frog->getHitbox().getPosition().y < frog->getHitbox().getSize().y);
}
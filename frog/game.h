#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"
#include "map.h"
#include "spriteDispenser.h"

class Game
{
public:
	Game(int tick_rate, int FPS);
	~Game();
	void run();
private:
	bool frogOnMeta();

	int tickrate;
	sf::RenderWindow* window;
	Frog* frog;
	Map* map;
	sf::Sprite background;
};


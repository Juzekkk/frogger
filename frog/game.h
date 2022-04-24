#pragma once
#include<SFML/Graphics.hpp>
#include"frog.h"
#include"map.h"

class Game
{
public:
	Game(int windowWidth, int windowHeight, int tick_rate, int FPS);
	void run();
private:
	int tickrate;
	sf::RenderWindow* window;
	Frog* frog;
	Map* map;
};


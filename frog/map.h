#pragma once
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "roadPlane.h"
#include "riverPlane.h"

class Map
{
public:
	Map(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	void nextLevel(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	void draw(sf::RenderWindow& window);
private:
	std::vector<Plane*> planes;
};


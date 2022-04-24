#include "map.h"

Map::Map(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	nextLevel(window, globalTickrate, frog);
}

void Map::performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : planes)
		x->performTick(window, globalTickrate, frog);

	//frog within boundries check
	if (frog.getShape().getPosition().x < -5 ||
		frog.getShape().getPosition().x > window.getSize().x - frog.getShape().getSize().x)
		frog.getShape().setPosition(0, window.getSize().y - frog.getShape().getSize().y);
}

void Map::nextLevel(sf::RenderWindow& window, int globalTickrate, Frog& frog) {
	for (auto& x : planes) {
		delete x;
	}
	planes.clear();
	for (int i = 1; i < window.getSize().y / 40 - 1; i++) {
		int roll = rand() % 100;
		if (roll % 3 == 0) {
			RoadPlane* temp = new RoadPlane(window, rand() % 2, i, globalTickrate);
			planes.push_back(temp);
		}
		else if (roll % 4 == 0) {
			RiverPlane* temp1 = new RiverPlane(window, rand() % 2, i, globalTickrate);
			planes.push_back(temp1);
		}
	}
}

void Map::draw(sf::RenderWindow& window) {
	for (auto& x : planes)
		x->draw(window);
}
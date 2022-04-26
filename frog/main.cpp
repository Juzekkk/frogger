#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <SFML/Graphics.hpp>

#include "game.h"

int main() {
	Game game(120, 240);
	game.run();
	return 0;
}
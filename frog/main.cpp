#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <SFML/Graphics.hpp>

#include "game.h"

int main() {
	Game game(240, 240);
	game.run();
	return 0;
}
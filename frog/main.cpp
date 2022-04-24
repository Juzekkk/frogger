#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <SFML/Graphics.hpp>

#include "game.h"

int main() {
	Game game(720, 720, 120, 240);
	game.run();
	return 0;
}
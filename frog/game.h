#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"
#include "map.h"
#include "spriteDispenser.h"

/**
 * \brief Game class.
 * G³ówna klasa wykonawcza aplikacji. 
 * Jest odpowiedzialna za za inicjacjê mapy, 
 * jednostki gracza oraz przechowywania globalnych ustawieñ obejmuj¹cych ca³¹ aplikacjê -
 * wymiarów okna, tickrate'u, liczny FPSów i grafiki t³a.
 */

class Game
{
public:
	/**
	 * \brief Konstruktor klasy Game.
	 * @param tick_rate odpowia za szybkoœæ wykonywania siê kolejnych ticków gry.
	 * @param FPS liczba klatek na sekundê gry.
	 */
	Game(int tick_rate, int FPS);
	/**
	 * \brief Destruktor klasy Game.
	 * Destruktor bior¹cy pod uwagê usuniêcie obiektów, a nie tylko wskaŸników do nich.
	 */
	~Game();
	/**
	 * \brief Metoda uruchamiaj¹ca grê.
	 */
	void run();
private:

	/**
	 * \brief Metoda sprawdzaj¹ca, czy gracz znalaz³ siê na linii mety. 
	 * Jeœli tak zwiêksza poziom trudnoœci i tworzy nowy level.
	 */
	bool frogOnMeta();
	int tickrate;
	sf::RenderWindow* window;
	Frog* frog;
	Map* map;
	sf::Sprite background;
};


#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"
#include "map.h"
#include "spriteDispenser.h"

/**
 * \brief Game class.
 * G��wna klasa wykonawcza aplikacji. 
 * Jest odpowiedzialna za za inicjacj� mapy, 
 * jednostki gracza oraz przechowywania globalnych ustawie� obejmuj�cych ca�� aplikacj� -
 * wymiar�w okna, tickrate'u, liczny FPS�w i grafiki t�a.
 */

class Game
{
public:
	/**
	 * \brief Konstruktor klasy Game.
	 * @param tick_rate odpowia za szybko�� wykonywania si� kolejnych tick�w gry.
	 * @param FPS liczba klatek na sekund� gry.
	 */
	Game(int tick_rate, int FPS);
	/**
	 * \brief Destruktor klasy Game.
	 * Destruktor bior�cy pod uwag� usuni�cie obiekt�w, a nie tylko wska�nik�w do nich.
	 */
	~Game();
	/**
	 * \brief Metoda uruchamiaj�ca gr�.
	 */
	void run();
private:

	/**
	 * \brief Metoda sprawdzaj�ca, czy gracz znalaz� si� na linii mety. 
	 * Je�li tak zwi�ksza poziom trudno�ci i tworzy nowy level.
	 */
	bool frogOnMeta();
	int tickrate;
	sf::RenderWindow* window;
	Frog* frog;
	Map* map;
	sf::Sprite background;
};


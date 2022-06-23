#pragma once
#include <SFML/Graphics.hpp>
#include "spriteDispenser.h"

/**
* \brief Frog Class.
* Klasa bêd¹ca jednostk¹ gracza.
* Zawiera w sobie mechanizm poruszania siê,
* reagowania na input gracza oraz mechanikê
* umierania.
*/
class Frog
{
public:
	/**
	* \brief Konstruktor klasy Frog.
	* @param windowSize rozmiar okna na którym rysowana jest mapa.
	*/
	Frog(sf::Vector2f windowSize);
	/**
	* \brief Metoda odpowiedzialna za rêczne sterowanie.
	* @param window okno na którym rysowana jest mapa.
	*/
	void move(sf::RenderWindow& window);
	/**
	* \brief Metoda odpowiedzialna za przesuniêcie ¿aby o dany wektor.
	* @param vector wektor przesuniêcia.
	*/
	void move(sf::Vector2f vector);
	/**
	* \brief Metoda odpowiedzialna za przesuniêcie ¿aby w miejsce startowe.
	* @param window okno na którym rysowana jest mapa.
	*/
	void die(sf::RenderWindow& window);
	sf::RectangleShape& getHitbox();
	/**
	* \brief Metoda odpowiedzialna za wyœwietlania ¿aby na mapie.
	* @param window okno na którym rysowana jest mapa.
	*/
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};


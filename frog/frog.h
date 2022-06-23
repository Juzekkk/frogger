#pragma once
#include <SFML/Graphics.hpp>
#include "spriteDispenser.h"

/**
* \brief Frog Class.
* Klasa b�d�ca jednostk� gracza.
* Zawiera w sobie mechanizm poruszania si�,
* reagowania na input gracza oraz mechanik�
* umierania.
*/
class Frog
{
public:
	/**
	* \brief Konstruktor klasy Frog.
	* @param windowSize rozmiar okna na kt�rym rysowana jest mapa.
	*/
	Frog(sf::Vector2f windowSize);
	/**
	* \brief Metoda odpowiedzialna za r�czne sterowanie.
	* @param window okno na kt�rym rysowana jest mapa.
	*/
	void move(sf::RenderWindow& window);
	/**
	* \brief Metoda odpowiedzialna za przesuni�cie �aby o dany wektor.
	* @param vector wektor przesuni�cia.
	*/
	void move(sf::Vector2f vector);
	/**
	* \brief Metoda odpowiedzialna za przesuni�cie �aby w miejsce startowe.
	* @param window okno na kt�rym rysowana jest mapa.
	*/
	void die(sf::RenderWindow& window);
	sf::RectangleShape& getHitbox();
	/**
	* \brief Metoda odpowiedzialna za wy�wietlania �aby na mapie.
	* @param window okno na kt�rym rysowana jest mapa.
	*/
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};


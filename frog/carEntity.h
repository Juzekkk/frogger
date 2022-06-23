#pragma once
#include "movingEntity.h"
#include "spriteDispenser.h"

/**
* \brief CarEntity Class.
* Klasa dziedziczy po klasie movingEntity.
* Klasa definiuj¹ca jednostkê samochodu.
* Samochód jest elementem, który zabija gracza jeœli na niego wkroczy.
*/
class CarEntity : public MovingEntity
{
public:
	/** \brief Konstruktor klasy CarEntity.
	*	@param size wektor okreœlaj¹cy rozmar jednostki.
	*	@param right wartoœæ logiczna okreœlaj¹ca kierunek ruchu jednostki.
	*	@param globalTickrate liczba ticków gry na jedn¹ klatkê.
	*	@param startingPosition pozycja startowa jednostki.
	*/
	CarEntity (sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	/**
	* \brief Metoda odpowiadaj¹ca za przeprowadzenie jednego tiku gry dla jednostki.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	/**
	* \brief Metoda odpowiadaj¹ca za przesuniêcie jednostki o jedn¹ d³ugoœæ w grze.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};
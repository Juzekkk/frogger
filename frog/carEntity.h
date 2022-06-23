#pragma once
#include "movingEntity.h"
#include "spriteDispenser.h"

/**
* \brief CarEntity Class.
* Klasa dziedziczy po klasie movingEntity.
* Klasa definiuj�ca jednostk� samochodu.
* Samoch�d jest elementem, kt�ry zabija gracza je�li na niego wkroczy.
*/
class CarEntity : public MovingEntity
{
public:
	/** \brief Konstruktor klasy CarEntity.
	*	@param size wektor okre�laj�cy rozmar jednostki.
	*	@param right warto�� logiczna okre�laj�ca kierunek ruchu jednostki.
	*	@param globalTickrate liczba tick�w gry na jedn� klatk�.
	*	@param startingPosition pozycja startowa jednostki.
	*/
	CarEntity (sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	/**
	* \brief Metoda odpowiadaj�ca za przeprowadzenie jednego tiku gry dla jednostki.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	/**
	* \brief Metoda odpowiadaj�ca za przesuni�cie jednostki o jedn� d�ugo�� w grze.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};
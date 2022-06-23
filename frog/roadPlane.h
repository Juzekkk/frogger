#pragma once
#include "plane.h"
#include "carEntity.h"
#include "spriteDispenser.h"

/**
* \brief RoadPlane Class.
* Klasa dzi�dzicz�ca po klasie Plane.
* Specjalny typ p�aszczyzny po kt�rej je�d�� samochody.
*/
class RoadPlane : public Plane
{
public:
	/**
	* \brief Konstruktor klasy RoadPlane.
	* @param window okno na kt�rym rysowana jest mapa.
	* @param right warto�� logiczna okre�laj�ca kierunek ruchu jednostek.
	* @param startingPosition pozycja startowa p�aszczyzny.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	*/
	RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	/**
	* \brief Metoda odpowiadaj�ca za przeprowadzenie jednego tiku gry dla wszystkich jednostek na p�aszczy�nie.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	/**
	* \brief Metoda odpowiadaj�ca za przesuni�cie wszystkich jednostek na p�aszczy�nie.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};


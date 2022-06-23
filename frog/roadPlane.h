#pragma once
#include "plane.h"
#include "carEntity.h"
#include "spriteDispenser.h"

/**
* \brief RoadPlane Class.
* Klasa dziêdzicz¹ca po klasie Plane.
* Specjalny typ p³aszczyzny po której je¿d¿¹ samochody.
*/
class RoadPlane : public Plane
{
public:
	/**
	* \brief Konstruktor klasy RoadPlane.
	* @param window okno na którym rysowana jest mapa.
	* @param right wartoœæ logiczna okreœlaj¹ca kierunek ruchu jednostek.
	* @param startingPosition pozycja startowa p³aszczyzny.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	*/
	RoadPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
	/**
	* \brief Metoda odpowiadaj¹ca za przeprowadzenie jednego tiku gry dla wszystkich jednostek na p³aszczyŸnie.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
private:
	/**
	* \brief Metoda odpowiadaj¹ca za przesuniêcie wszystkich jednostek na p³aszczyŸnie.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
};


#pragma once
#include "plane.h"
#include "logEntity.h"
#include "spriteDispenser.h"

/**
* \brief RiverPlane Class.
* Klasa dzi�dzicz�ca po klasie Plane.
* Specjalny typ p�aszczyzny po kt�rej p�ywaj� k�ody.
* P�aszczyzna ta zabija gracza, je�li nie znajduje si� on na �adnej z k��d.
*/
class RiverPlane : public Plane
{
public:
	/**
	* \brief Konstruktor klasy RiverPlane.
	* @param window okno na kt�rym rysowana jest mapa.
	* @param right warto�� logiczna okre�laj�ca kierunek ruchu jednostek.
	* @param startingPosition pozycja startowa p�aszczyzny.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	*/
	RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
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
	/**
	* \brief Metoda zwracaj�ca warto�� logiczn� m�wi�c� o tym, czy gracz znajduje si� na p�aszczy�nie.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param frog referencja do jednostki gracza.
	*/
	bool frogOnRiver(sf::RenderWindow& window, Frog& frog);
	/**
	* \brief Metoda zwracaj�ca warto�� logiczn� m�wi�c� o tym, czy gracz znajduje si� na kt�rej� z k��d.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param frog referencja do jednostki gracza.
	*/
	bool frogOnLog(sf::RenderWindow& window, Frog& frog);
};
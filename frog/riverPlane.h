#pragma once
#include "plane.h"
#include "logEntity.h"
#include "spriteDispenser.h"

/**
* \brief RiverPlane Class.
* Klasa dziêdzicz¹ca po klasie Plane.
* Specjalny typ p³aszczyzny po której p³ywaj¹ k³ody.
* P³aszczyzna ta zabija gracza, jeœli nie znajduje siê on na ¿adnej z k³ód.
*/
class RiverPlane : public Plane
{
public:
	/**
	* \brief Konstruktor klasy RiverPlane.
	* @param window okno na którym rysowana jest mapa.
	* @param right wartoœæ logiczna okreœlaj¹ca kierunek ruchu jednostek.
	* @param startingPosition pozycja startowa p³aszczyzny.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	*/
	RiverPlane(sf::RenderWindow& window, bool right, int startingPosition, int globalTickrate);
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
	/**
	* \brief Metoda zwracaj¹ca wartoœæ logiczn¹ mówi¹c¹ o tym, czy gracz znajduje siê na p³aszczyŸnie.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param frog referencja do jednostki gracza.
	*/
	bool frogOnRiver(sf::RenderWindow& window, Frog& frog);
	/**
	* \brief Metoda zwracaj¹ca wartoœæ logiczn¹ mówi¹c¹ o tym, czy gracz znajduje siê na którejœ z k³ód.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param frog referencja do jednostki gracza.
	*/
	bool frogOnLog(sf::RenderWindow& window, Frog& frog);
};
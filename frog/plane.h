#pragma once
#include <SFML/Graphics.hpp>
#include "movingEntity.h"
#include "frog.h"
#include <iostream>

/**
* \brief Plane Class.
* Klasa definiuj¹ca podstawow¹ p³aszczyznê w grze.
* P³aszczyzna zawiera w sobie równie¿ mechanizm
* tworzenia ruchomych jednostek oraz wywo³uje ich ruch.
*/
class Plane
{
public:
	/**
	* \brief Konstruktor klasy Plane.
	* @param window okno na którym rysowana jest mapa.
	* @param right wartoœæ logiczna okreœlaj¹ca kierunek ruchu jednostek.
	* @param positionY poziom na którym znajduje siê p³aszczyzna na mapie.
	*/
	Plane(sf::RenderWindow& window, bool right, int positionY);
	/**
	* \brief Destruktor klasy Plane.
	* Destruktor bior¹cy pod uwagê niszczenie nie tylko wskaŸników do obiektów, ale równie¿ samych obiektów.
	*/
	~Plane();
	/**
	* \brief Metoda zwracaj¹ca hitbox p³aszczyzny.
	*/
	sf::RectangleShape& getHitbox();
	/**
	* \brief Metoda wyœwietlaj¹ca p³aszczyznê w oknie.
	* @param window okno na którym rysowana jest mapa.
	*/
	void draw(sf::RenderWindow& window);
	/**
	* \brief Metoda wirtualna.
	*/
	virtual void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);

protected:
	/**
	* \brief Metoda wirtualna.
	*/
	virtual void moveElements(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Metoda zwracaj¹ca listê ruchomych jednostek danej p³aszczyzny.
	*/
	std::vector<MovingEntity*> getElements();
	
	bool isRight;
	std::vector<MovingEntity*> movingEntities;
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};
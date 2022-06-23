#pragma once
#include <SFML/Graphics.hpp>
#include "movingEntity.h"
#include "frog.h"
#include <iostream>

/**
* \brief Plane Class.
* Klasa definiuj�ca podstawow� p�aszczyzn� w grze.
* P�aszczyzna zawiera w sobie r�wnie� mechanizm
* tworzenia ruchomych jednostek oraz wywo�uje ich ruch.
*/
class Plane
{
public:
	/**
	* \brief Konstruktor klasy Plane.
	* @param window okno na kt�rym rysowana jest mapa.
	* @param right warto�� logiczna okre�laj�ca kierunek ruchu jednostek.
	* @param positionY poziom na kt�rym znajduje si� p�aszczyzna na mapie.
	*/
	Plane(sf::RenderWindow& window, bool right, int positionY);
	/**
	* \brief Destruktor klasy Plane.
	* Destruktor bior�cy pod uwag� niszczenie nie tylko wska�nik�w do obiekt�w, ale r�wnie� samych obiekt�w.
	*/
	~Plane();
	/**
	* \brief Metoda zwracaj�ca hitbox p�aszczyzny.
	*/
	sf::RectangleShape& getHitbox();
	/**
	* \brief Metoda wy�wietlaj�ca p�aszczyzn� w oknie.
	* @param window okno na kt�rym rysowana jest mapa.
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
	* \brief Metoda zwracaj�ca list� ruchomych jednostek danej p�aszczyzny.
	*/
	std::vector<MovingEntity*> getElements();
	
	bool isRight;
	std::vector<MovingEntity*> movingEntities;
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};
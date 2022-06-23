#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"


/**
* \brief MovingEntity Class.
* Klasa definiuj�ca bazow� ruchom� jednostk�.
*/
class MovingEntity
{
public:
	/** \brief Konstruktor klasy MovingEntity.
	*	@param size wektor okre�laj�cy rozmar jednostki.
	*	@param right warto�� logiczna okre�laj�ca kierunek ruchu jednostki.
	*	@param globalTickrate liczba tick�w gry na jedn� klatk�.
	*	@param startingPosition pozycja startowa jednostki.
	*/
	MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	/** \brief Metoda zwracaj�ca warto�� logiczn� m�wi�c� o tym, czy gracz znajduje si� na jednostce.
	*	@param window okno na kt�rym rysowana jest mapa.
	*	@param frog referencja do jednostki gracza.
	*/
	bool frogOnObject(sf::RenderWindow& window, Frog& frog);
	/** \brief Metoda odpowiadaj�ca za adaptacj� rozmiar�w i pozycji tekstury do hitboxa.
	*/
	void reloadTexture();
	/** \brief Metoda zwracaj�ca referencj� do hitboxa.
	*/
	sf::RectangleShape& getHitbox();
	/** \brief Metoda wy�wietlaj�ca jednostk� w oknie.
	*	@param window okno na kt�rym rysowana jest mapa.
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
	virtual void move(sf::RenderWindow& window, int globalTickrate, Frog& frog);

	bool isRight;
	int tickrate;
	sf::RectangleShape hitbox;
	sf::Sprite graphic;
};

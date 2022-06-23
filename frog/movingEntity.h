#pragma once
#include <SFML/Graphics.hpp>
#include "frog.h"


/**
* \brief MovingEntity Class.
* Klasa definiuj¹ca bazow¹ ruchom¹ jednostkê.
*/
class MovingEntity
{
public:
	/** \brief Konstruktor klasy MovingEntity.
	*	@param size wektor okreœlaj¹cy rozmar jednostki.
	*	@param right wartoœæ logiczna okreœlaj¹ca kierunek ruchu jednostki.
	*	@param globalTickrate liczba ticków gry na jedn¹ klatkê.
	*	@param startingPosition pozycja startowa jednostki.
	*/
	MovingEntity(sf::Vector2f size, bool right, int globalTickrate, sf::Vector2f startingPosition);
	/** \brief Metoda zwracaj¹ca wartoœæ logiczn¹ mówi¹c¹ o tym, czy gracz znajduje siê na jednostce.
	*	@param window okno na którym rysowana jest mapa.
	*	@param frog referencja do jednostki gracza.
	*/
	bool frogOnObject(sf::RenderWindow& window, Frog& frog);
	/** \brief Metoda odpowiadaj¹ca za adaptacjê rozmiarów i pozycji tekstury do hitboxa.
	*/
	void reloadTexture();
	/** \brief Metoda zwracaj¹ca referencjê do hitboxa.
	*/
	sf::RectangleShape& getHitbox();
	/** \brief Metoda wyœwietlaj¹ca jednostkê w oknie.
	*	@param window okno na którym rysowana jest mapa.
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

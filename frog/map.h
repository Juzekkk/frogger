#pragma once
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "roadPlane.h"
#include "riverPlane.h"


/**
* \brief Map Class.
* Klasa zawieraj¹ca w sobie wszystkie jednostki na mapie.
* Odpowiada za przechowywania elementów otoczenia oraz 
* wszystkich ruchomych jednostek w grze, w tym jednostki gracza.
*/
class Map
{
public:
	/**
	* \brief Konstruktor klasy Map.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	Map(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Destruktor klasy Map.
	* Destruktor bior¹cy pod uwagê niszczenie nie tylko wskaŸników do obiektów, ale równie¿ samych obiektów.
	*/
	~Map();
	/**
	* \brief Metoda odpowiadaj¹ca za stworzenie nowo, losowo wygenerowanej mapy.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	void nextLevel(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Metoda odpowiadaj¹ca za przeprowadzenie jednego tiku gry dla wszystkich jednostek na mapie.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	* @param globalTickrate liczba ticków gry na jedn¹ klatkê.
	* @param frog referencja do jednostki gracza.
	*/
	void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Metoda odpowiadaj¹ca za narysowanie mapy.
	* @param window referencja do okna na którym wyœwietlana jest mapa.
	*/
	void draw(sf::RenderWindow& window);
private:
	std::vector<Plane*> planes;
};


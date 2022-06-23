#pragma once
#include <SFML/Graphics.hpp>
#include "plane.h"
#include "roadPlane.h"
#include "riverPlane.h"


/**
* \brief Map Class.
* Klasa zawieraj�ca w sobie wszystkie jednostki na mapie.
* Odpowiada za przechowywania element�w otoczenia oraz 
* wszystkich ruchomych jednostek w grze, w tym jednostki gracza.
*/
class Map
{
public:
	/**
	* \brief Konstruktor klasy Map.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	Map(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Destruktor klasy Map.
	* Destruktor bior�cy pod uwag� niszczenie nie tylko wska�nik�w do obiekt�w, ale r�wnie� samych obiekt�w.
	*/
	~Map();
	/**
	* \brief Metoda odpowiadaj�ca za stworzenie nowo, losowo wygenerowanej mapy.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	void nextLevel(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Metoda odpowiadaj�ca za przeprowadzenie jednego tiku gry dla wszystkich jednostek na mapie.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	* @param globalTickrate liczba tick�w gry na jedn� klatk�.
	* @param frog referencja do jednostki gracza.
	*/
	void performTick(sf::RenderWindow& window, int globalTickrate, Frog& frog);
	/**
	* \brief Metoda odpowiadaj�ca za narysowanie mapy.
	* @param window referencja do okna na kt�rym wy�wietlana jest mapa.
	*/
	void draw(sf::RenderWindow& window);
private:
	std::vector<Plane*> planes;
};


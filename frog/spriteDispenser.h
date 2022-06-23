#pragma once
#include <map>
#include <SFML/Graphics.hpp>

/**
* \brief SpriteDispenser Class.
* Klasa odpowiedzialna za dystrybucjê tekstur jednostkom w grze.
*/
class SpriteDispenser
{
public:
	/**
	* \brief Statyczna metoda zwracaj¹ca pointer do tekstury danego typu.
	* @param type okreœla typ tekstury która jest zwracana.
	*/
	static sf::Texture* getTexturePoiner(std::string type);
private:
	static std::map<std::string, sf::Texture*> textures;
};
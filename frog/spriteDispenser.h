#pragma once
#include <map>
#include <SFML/Graphics.hpp>

/**
* \brief SpriteDispenser Class.
* Klasa odpowiedzialna za dystrybucj� tekstur jednostkom w grze.
*/
class SpriteDispenser
{
public:
	/**
	* \brief Statyczna metoda zwracaj�ca pointer do tekstury danego typu.
	* @param type okre�la typ tekstury kt�ra jest zwracana.
	*/
	static sf::Texture* getTexturePoiner(std::string type);
private:
	static std::map<std::string, sf::Texture*> textures;
};
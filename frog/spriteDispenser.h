#pragma once
#include <map>
#include <SFML/Graphics.hpp>
class SpriteDispenser
{
public:
	static sf::Texture* getTexturePoiner(std::string type);
private:
	static std::map<std::string, sf::Texture*> textures;
};
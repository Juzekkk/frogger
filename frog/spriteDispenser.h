#pragma once
#include <map>
#include <SFML/Graphics.hpp>
class SpriteDispenser
{
private:
	static std::map<std::string, sf::Texture*> textures;
public:
	static sf::Texture* getTexturePoiner(std::string type);
};
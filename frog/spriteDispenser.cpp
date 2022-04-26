#include "spriteDispenser.h"

std::map<std::string, sf::Texture*> SpriteDispenser::textures = [] {
	// Names
	std::vector<std::string> names;
	names.push_back("frog.png");
	names.push_back("car.png");
	names.push_back("carBlue.png");
	names.push_back("carRed.png");
	names.push_back("grass.jpg");
	names.push_back("log.png");
	names.push_back("road.jpg");
	names.push_back("water.jpg");

	// Textures
	std::map<std::string, sf::Texture*> textures;
	for (auto& x : names) {
		sf::Texture* temp = new sf::Texture;
		temp->setRepeated(true);
		if (temp->loadFromFile("images/" + x)) {
			textures.insert(std::make_pair(x.substr(0, x.size() - 4), temp));
		}
	}
	return textures;
}();

sf::Texture* SpriteDispenser::getTexturePoiner(std::string type) {
	return textures[type];
}
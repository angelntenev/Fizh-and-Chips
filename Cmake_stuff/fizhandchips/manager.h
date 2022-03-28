// manager.h
#pragma once

#include <SFML/Graphics.hpp>
#include "fish.h"

class Manager
{
protected:
	int chipsScore;
	sf::Text scoreText;
	sf::Font font;
	std::vector<Fish*> fishes;
	sf::Texture spritesheet2;
public:
	Manager();
	void Update(float& dt);
	void changeScore(int a);
	sf::Text getText();
	std::vector<Fish*> getFish();
};
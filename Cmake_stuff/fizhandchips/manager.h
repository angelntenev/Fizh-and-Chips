// manager.h
#pragma once

#include <SFML/Graphics.hpp>
#include "fish.h"
//#include "carnivore.h"
#include "fallingObjects.h"

class Manager
{
protected:
	int chipsScore;
	sf::Text scoreText;
	sf::Font font;
	std::vector<Fish*> fishes;
	//std::vector<Carnivore*> carnivores;
	std::vector<Consumable*> foodObjects;
	sf::Texture spritesheet2;
public:
	Manager();
	void Update(float& dt);
	void changeScore(int a);
	sf::Text getText();
	std::vector<Fish*> getFish();
	//std::vector < Carnivore*> getCarnivore();
	void Render(sf::RenderWindow& window);
};
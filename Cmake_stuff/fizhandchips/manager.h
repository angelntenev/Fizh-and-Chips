// manager.h
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include "fish.h"
#include "fallingObjects.h"


class Manager
{
protected:
	int chipsScore;
	sf::Text scoreText;
	sf::Font font;
	std::vector<Fish*> fishes;
	std::vector<Consumable*> foodObjects;
	std::vector<Consumable*> currencyObjects;
	sf::Texture spritesheet2;
	float buyTimer = 0.1, feedTimer = 0.1;
public:
	Manager();
	void Update(float& dt);
	void changeScore(int a);
	float closestPoint(Vector2f obj1, Vector2f obj2);
	void moveToClosestPoint(Fish& fish);
	sf::Text getText();
	std::vector<Fish*> getFish();
	int getChips();
	void setChips(int chips);
	void addChips(int chips);
	void Render(sf::RenderWindow& window);
};
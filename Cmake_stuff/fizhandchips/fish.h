// fish.h
#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Fish : public Entity
{
private:
	float speed;
	bool direction;
	float hungerTimer = 5;
	RectangleShape mouthPiece;
public:
	Fish();
	void Update(float& dt) override;
	RectangleShape getMouth();
	void setBothDirection();
	void moveTowardsWithMouth(sf::Vector2f& destination, float& speed, float& dt);
	void fishReset();
	void resetHungerTimer();
	void SpeedUP();
	bool isHungry = false;
};
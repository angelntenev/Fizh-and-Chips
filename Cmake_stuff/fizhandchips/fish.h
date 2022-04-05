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
	sf::Vector2f destination;
	const sf::Vector2f getRandomPos();
	float distanceX, distanceY;
	int state;
	bool direction;
	bool isHungry = false;
	float idle;
	float hungertimer = 10;
	RectangleShape mouthPiece;
public:
	Fish();
	void Update(float& dt) override;
	void Reset();
	void setDirection();
	RectangleShape getMouth();
};
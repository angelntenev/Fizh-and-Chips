// fish.h
#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Fish : public Entity
{
private:
	float speed;
	sf::Vector2f destination;
	const sf::Vector2f getRandomPos();
	float distanceX, distanceY;
	int state;
	bool direction;
public:
	Fish();
	void Update(float& dt) override;
	void Reset();
	void setDirection();
};
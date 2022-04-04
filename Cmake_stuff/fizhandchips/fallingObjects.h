// fallingObjects.h
#pragma once
#include "entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
using namespace std;
using namespace sf;

class Consumable : public Entity
{
protected:
	float fallSpeed;
	bool collectable;
	float timeOnFloor;
public:
	Consumable(bool _isCollectable, sf::Vector2f startLoc);
	void Update(float& dt) override;
	void setfallSpeed(float speed);
	void setCollectable(bool _isCollectable);
	~Consumable();
};
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
	int value;
public:
	Consumable(bool _isCollectable, sf::Vector2f startLoc, int pos1, int pos2, int value);
	void Update(float& dt) override;
	void setfallSpeed(float speed);
	void setCollectable(bool _isCollectable);
	void setValue(int value);
	int getValue();
	~Consumable();
};
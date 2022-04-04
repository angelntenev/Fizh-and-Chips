// fallingObjects.h
#pragma once
#include "entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>

class Consumable : public Entity
{
protected:
	float fallSpeed;
	bool collectable;
public:
	Consumable(bool _isCollectable, sf::Vector2f startLoc);
	void Update(float& dt) override;
	void setfallSpeed(float speed);
	void setCollectable(bool _isCollectable);
};
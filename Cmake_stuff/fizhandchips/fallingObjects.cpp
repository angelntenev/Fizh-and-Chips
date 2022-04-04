// fallingObjects.cpp

#include "fish.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "fallingObjects.h"
using namespace std;
using namespace sf;

Consumable::Consumable(bool _isCollectable, Vector2f startLoc) : fallSpeed(20), Entity(IntRect(Vector2(32, 0), Vector2(32, 32)))
{
	setCollectable(_isCollectable);
	setOrigin(Vector2f(16, 16));
	setPosition(startLoc);

}


void Consumable::setCollectable(bool _isCollectable)
{
	Consumable::collectable = _isCollectable;
}

void Consumable::setfallSpeed(float speed)
{
	Consumable::fallSpeed = speed;
}

void Consumable::Update(float& dt)
{
	Entity::Update(dt);

	Consumable::move(Vector2f(0, dt * fallSpeed));
}
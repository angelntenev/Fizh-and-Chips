#include "animations.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

Anim::Anim(Vector2f loc) : Entity(IntRect(Vector2(0, 0), Vector2(32, 32)))
{
	_sprite = IntRect(Vector2(0, 0), Vector2(32, 32));
	setOrigin(Vector2f(16.f, 16.f));
	setTextureRect(_sprite);
	setTexture(shootTexture);
	setScale(Vector2f(2.f, 2.f));
	setPosition(loc);
}

void Anim::Update(float& dt)
{
	if (shot == false)
	{
		if (clock.getElapsedTime().asSeconds() > 0.03f)
		{
			if (_sprite.left == 192)
			{
				_sprite.left = 0;
				shot = true;
				setPosition(Vector2f(-100.f, -100.f));
				_fordeletion = true;
			}
			else
			{
				_sprite.left += 32;
			}
			setTextureRect(_sprite);
			clock.restart();
		}
	}
}

void Anim::setLoc(Vector2f loc)
{
	setPosition(loc);
}

void Anim::resetShot()
{
	_sprite.left = 0;
	shot = false;
}

bool Anim::getHit()
{
	return hit;
}

void Anim::setHit(bool hitResult)
{
	hit = hitResult;
}
#include "animations.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

Anim::Anim() : Entity(IntRect(Vector2(0, 0), Vector2(32, 32)))
{
	_sprite = IntRect(Vector2(0, 0), Vector2(32, 32));

	setTextureRect(_sprite);
	setTexture(shootTexture);
}
// entity.cpp
#include "entity.h"
#include "game.h"
using namespace std;
using namespace sf;

//Player Controls for moving crosshair
const Keyboard::Key controls[4] =
{
    Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D
};

Entity::Entity(IntRect ir) : sf::Sprite()
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
}


const Vector2f Entity::reachPosition() { return getPosition(); }


void Entity::Update(float& dt) {


}

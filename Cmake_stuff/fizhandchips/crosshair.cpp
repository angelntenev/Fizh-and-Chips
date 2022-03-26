// crosshair.cpp
#include "crosshair.h"
#include "game.h"
#include <iostream>


using namespace std;
using namespace sf;

//Player Controls for moving crosshair
const Keyboard::Key controls[4] =
{
    Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D
};

Crosshair::Crosshair() : _speed(1000), Entity(IntRect(Vector2(0, 0), Vector2(32, 32)))
{
    setOrigin(Vector2f(16, 16));
    Crosshair::setPosition(Vector2f(screenWidth * .5f, screenHeight * .5f));
}
//
//Moving crosshair in four directions based on keys
void Crosshair::Update(float& dt)
{
    Entity::Update(dt);

    float direction_x = 0.0f, direction_y = 0.0f;
    if (Keyboard::isKeyPressed(controls[0]))
    {
        if (!(Crosshair::reachPosition().y < 0))
        {
            direction_y--;
        }
    }
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (!(Crosshair::reachPosition().y > screenHeight))
        {
            direction_y++;
        }
    }
    if (Keyboard::isKeyPressed(controls[2]))
    {
        if (!(Crosshair::reachPosition().x < 0))
        {
            direction_x--;
        }
    }
    if (Keyboard::isKeyPressed(controls[3]))
    {
        if (!(Crosshair::reachPosition().x > screenWidth))
        {
            direction_x++;
        }
    }

    Crosshair::move(Vector2f(direction_x * _speed * dt, direction_y * _speed * dt));
}

//Crosshair::Crosshair()  : Entity(IntRect(Vector2(0, 0), Vector2(32, 32))) {
//    //setOrigin(Vector2f(16, 16));
//    //setPosition({ screenWidth / 2, screenHeight / 2 });
//}


// fish.cpp
#include "fish.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <random>
using namespace std;
using namespace sf;

sf::Vector2f startPoint;



Fish::Fish() : speed(100), Entity(IntRect(Vector2(32, 0), Vector2(32, 32)))
{
    setOrigin(Vector2f(16, 16));
    startPoint = Fish::getRandomPos();
    Fish::setPosition(startPoint);
    destination = Fish::getRandomPos();
    setDirection();

}

const Vector2f Fish::getRandomPos()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, screenWidth); // distribution in range [1, 6]
    std::uniform_int_distribution<std::mt19937::result_type> dist7(0, screenHeight);
    return Vector2f(dist6(rng), dist7(rng));
}

void Fish::Update(float& dt)
{
    Entity::Update(dt);


    if (distanceX > 0 && distanceY > 0)
    {
        switch (state)
        {
        case 1:
            Fish::move(Vector2f(speed * dt, speed * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 2:
            Fish::move(Vector2f(speed * dt, (-speed) * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 3:
            Fish::move(Vector2f((-speed) * dt, speed * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 4:
            Fish::move(Vector2f((-speed) * dt, (-speed) * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        }
    }
    else
    {
        Reset();
    }
}

void Fish::Reset()
{
    startPoint = Fish::reachPosition();
    destination = Fish::getRandomPos();
    setDirection();
}

void Fish::setDirection()
{
    if (startPoint.x < destination.x && startPoint.y < destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = destination.y - startPoint.y;

        state = 1;
        direction = true;
        Fish::setScale(Vector2f(1, 1));
    }
    else if (startPoint.x < destination.x && startPoint.y > destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = startPoint.y - destination.y;

        state = 2;
        direction = true;
        Fish::setScale(Vector2f(1, 1));
    }
    else if (startPoint.x > destination.x && startPoint.y < destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = destination.y - startPoint.y;

        state = 3;
        direction = false;
        Fish::setScale(Vector2f(-1, 1));
    }
    else if (startPoint.x > destination.x && startPoint.y > destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = startPoint.y - destination.y;

        state = 4;
        direction = false;
        Fish::setScale(Vector2f(-1, 1));
    }
}
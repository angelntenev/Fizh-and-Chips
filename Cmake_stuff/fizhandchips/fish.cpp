// fish.cpp
#include "fish.h"
#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;





Fish::Fish() : speed(0.25), Entity(IntRect(Vector2(32, 0), Vector2(32, 32)))
{
    setOrigin(Vector2f(16, 16));
    startPoint = getRandomPos();
    Fish::setPosition(getStartPoint());
    destination = getRandomPos();
    setDirection();
    Vector2f mouthPos = Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y + 2);
    Vector2f mouthSize = Vector2f(6, 6);
    mouthPiece.setOrigin(Vector2f(3, 3));
    mouthPiece.setPosition(mouthPos);
    mouthPiece.setSize(mouthSize);
    mouthPiece.setFillColor(Color::White);
}

void Fish::Update(float& dt)
{
    Entity::Update(dt);
    hungerTimer -= dt;
    if (hungerTimer > 0)
    {
        Fish::moveTowardsWithMouth(destination, speed, dt);
    }
    else
    {
        Fish::moveTowardsWithMouth(destination, speed, dt);
        
        isHungry = true;
    }
}

RectangleShape Fish::getMouth()
{
    return Fish::mouthPiece;
}

void Fish::setBothDirection()
{
    if (startPoint.x < destination.x && startPoint.y < destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = destination.y - startPoint.y;

        state = 1;
        direction = true;
        Fish::setScale(Vector2f(1, 1));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x < destination.x && startPoint.y > destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = startPoint.y - destination.y;

        state = 2;
        direction = true;
        Fish::setScale(Vector2f(1, 1));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x > destination.x && startPoint.y < destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = destination.y - startPoint.y;

        state = 3;
        direction = false;
        Fish::setScale(Vector2f(-1, 1));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x - 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x > destination.x && startPoint.y > destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = startPoint.y - destination.y;
        state = 4;
        direction = false;
        Fish::setScale(Vector2f(-1, 1));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x - 7, Fish::getPosition().y + 2));
    }

    startDistanceX = distanceX;
    startDistanceY = distanceY;
}

void Fish::moveTowardsWithMouth(Vector2f& destination, float& speed, float& dt)
{
    if (distanceX > 0 && distanceY > 0)
    {
        switch (state)
        {
        case 1:
            Fish::move(Vector2f(startDistanceX * (speed * dt), startDistanceY * (speed * dt)));
            Fish::mouthPiece.move(Vector2f(startDistanceX * (speed * dt), startDistanceY * (speed * dt)));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 2:
            Fish::move(Vector2f(startDistanceX * (speed * dt), startDistanceY * ((-speed) * dt)));
            Fish::mouthPiece.move(Vector2f(startDistanceX * (speed * dt), startDistanceY * ((-speed) * dt)));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 3:
            Fish::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * (speed * dt)));
            Fish::mouthPiece.move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * (speed * dt)));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 4:
            Fish::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * ((-speed) * dt)));
            Fish::mouthPiece.move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * ((-speed) * dt)));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        }
    }
    else
    {
        idle -= dt;
        if (idle < 0)
        {
            fishReset();
        }
    }
}

void Fish::fishReset()
{
    startPoint = Entity::reachPosition();
    destination = Entity::getRandomPos();
    setBothDirection();
    idle = getRandomNumber(3,6);
}

void Fish::resetHungerTimer()
{
    hungerTimer = 20;
    isHungry = false;
}

void Fish::SpeedUP()
{
    speed = 1;
}
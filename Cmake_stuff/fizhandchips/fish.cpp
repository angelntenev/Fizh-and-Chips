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
    buffer.loadFromFile("res/Recording.ogg");
    sound.setBuffer(buffer);
}

void Fish::Update(float& dt)
{
    Entity::Update(dt);
    hungerTimer -= dt;
    coinCounter -= dt;
    if (hungerTimer > 0)
    {
        Fish::moveTowardsWithMouth(destination, speed, dt);
    }
    if (hungerTimer < -10)
    {
        setDeadFish();
    }
    else
    {
        Fish::moveTowardsWithMouth(destination, speed, dt);
        
        isHungry = true;
    }
    //if (Fish::getPosition().y >= 780.f)
    //{
    //    speed = 0;
    //}
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
        if (scaleX < 0)
        {
            scaleX = scaleX * (-1);
        }
        if (scaleY < 0)
        {
            scaleY = scaleY * (-1);
        }
        Fish::setScale(Vector2f(scaleX, scaleY));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x < destination.x && startPoint.y > destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = startPoint.y - destination.y;

        state = 2;
        direction = true;
        if (scaleX < 0)
        {
            scaleX = scaleX * (-1);
        }
        if (scaleY < 0)
        {
            scaleY = scaleY * (-1);
        }
        Fish::setScale(Vector2f(scaleX, scaleY));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x > destination.x && startPoint.y < destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = destination.y - startPoint.y;

        state = 3;
        direction = false;
        if (scaleX > 0)
        {
            scaleX = scaleX * (-1);
        }
        if (scaleY < 0)
        {
            scaleY = scaleY * (-1);
        }
        Fish::setScale(Vector2f(scaleX, scaleY));
        mouthPiece.setPosition(Vector2f(Fish::getPosition().x - 7, Fish::getPosition().y + 2));
    }
    else if (startPoint.x > destination.x && startPoint.y > destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = startPoint.y - destination.y;
        state = 4;
        direction = false;
        if (scaleX > 0)
        {
            scaleX = scaleX * (-1);
        }
        if (scaleY < 0)
        {
            scaleY = scaleY * (-1);
        }
        Fish::setScale(Vector2f(scaleX, scaleY));
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
                distanceX = distanceX - (startDistanceX * (speed * dt));
                Fish::mouthPiece.move(Vector2f(startDistanceX * (speed * dt), startDistanceY * (speed * dt)));
                distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 2:
                Fish::move(Vector2f(startDistanceX * (speed * dt), startDistanceY * ((-speed) * dt)));
                distanceX = distanceX - (startDistanceX * (speed * dt));
                Fish::mouthPiece.move(Vector2f(startDistanceX * (speed * dt), startDistanceY * ((-speed) * dt)));
                distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 3:
                Fish::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * (speed * dt)));
                distanceX = distanceX - (startDistanceX * (speed * dt));
                Fish::mouthPiece.move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * (speed * dt)));
                distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 4:
                Fish::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * ((-speed) * dt)));
                distanceX = distanceX - (startDistanceX * (speed * dt));
                Fish::mouthPiece.move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * ((-speed) * dt)));
                distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        }
    }
    else
    {
        idle -= dt;
        Fish::setScale(Vector2f(scaleX, scaleY));
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
    Fish::setBothDirection();
    idle = getRandomNumber(2,5);
}

void Fish::resetHungerTimer()
{
    hungerTimer = 20;
    isHungry = false;
}

float Fish::getCoinCounter()
{
    return coinCounter;
}

void Fish::resetCoinCounter()
{
    coinCounter = getRandomNumber(16, 22);
}

int Fish::getSizeGrowth()
{
    return size;
}

void Fish::setSizeGrowth(int _size)
{
    size = _size;
}

int Fish::getXP()
{
    return xp;
}

void Fish::giveXP()
{
    xp += getRandomNumber(8, 11);
}

void Fish::Grow1()
{
    if (scaleX < 0)
    {
        scaleX = -1.5;
    }
    else
    {
        scaleX = 1.5;
    }
    if (scaleY < 0)
    {
        scaleY = -1.5;
    }
    else
    {
        scaleY = 1.5;
    }
}

void Fish::Grow2()
{
    if (scaleX < 0)
    {
        scaleX = 2;
    }
    else
    {
        scaleX = 2;
    }
    if (scaleY < 2)
    {
        scaleY = 2;
    }
    else
    {
        scaleY = 2;
    }
}

void Fish::setHungryFish()
{
    _sprite = IntRect(Vector2(128, 0), Vector2(32, 32));
    setTextureRect(_sprite);
}

void Fish::setFullFish()
{
    _sprite = IntRect(Vector2(32, 0), Vector2(32, 32));
    setTextureRect(_sprite);
}

void Fish::setDeadFish()
{
    _sprite = IntRect(Vector2(160, 0), Vector2(32, 32));
    setTextureRect(_sprite);
}

void Fish::playGulp()
{
    sound.play();
}

void Fish::resetSpeed()
{
    speed = 0.25;
}

void Fish::setSpeed(float _speed)
{
    speed = _speed;
}

void Fish::setSharkSprite()
{
    _sprite = IntRect(Vector2(0, 0), Vector2(128, 64));
    setTexture(spritesheetShark);
    setTextureRect(_sprite);
}

void Fish::setHungryShark()
{
    _sprite = IntRect(Vector2(128, 0), Vector2(128, 64));
    setTexture(spritesheetShark);
    setTextureRect(_sprite);
}

void Fish::setSharkNotHungry()
{
    _sprite = IntRect(Vector2(0, 0), Vector2(128, 64));
    setTexture(spritesheetShark);
    setTextureRect(_sprite);
}

void Fish::setDeadShark()
{
    _sprite = IntRect(Vector2(256, 0), Vector2(128, 64));
    setTexture(spritesheetShark);
    setTextureRect(_sprite);
}

void Fish::setBossEnemySprite()
{
    _sprite = IntRect(Vector2(0, 0), Vector2(64, 64));
    setTexture(spritesheetBossEnemy);
    setTextureRect(_sprite);
}

float Fish::getHungerTimer()
{
    return hungerTimer;
}



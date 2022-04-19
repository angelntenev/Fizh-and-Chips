// entity.cpp
#include "entity.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <random>
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

void Entity::moveTowards(Vector2f& destination, float& speed, float& dt)
{
    if (distanceX > 0 && distanceY > 0)
    {
        switch (state)
        {
        case 1:
            Entity::move(Vector2f(startDistanceX * (speed * dt), startDistanceY * (speed * dt)));
            //Fish::mouthPiece.move(Vector2f(speed * dt, speed * dt));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 2:
            Entity::move(Vector2f(startDistanceX * (speed * dt), startDistanceY * ((-speed) * dt)));
            //Fish::mouthPiece.move(Vector2f(speed * dt, (-speed) * dt));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 3:
            Entity::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * (speed * dt)));
            //Fish::mouthPiece.move(Vector2f((-speed) * dt, speed * dt));
            distanceX = distanceX - (startDistanceX * (speed * dt));
            distanceY = distanceY - (startDistanceY * (speed * dt));
            break;
        case 4:
            Entity::move(Vector2f(startDistanceX * ((-speed) * dt), startDistanceY * ((-speed) * dt)));
            //Fish::mouthPiece.move(Vector2f((-speed) * dt, (-speed) * dt));
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
            Entity::Reset();
        }
    }
}


void Entity::setDirection()
{
    if (startPoint.x < destination.x && startPoint.y < destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = destination.y - startPoint.y;

        state = 1;
        direction = true;
        Entity::setScale(Vector2f(1, 1));
        //mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y - 3));
    }
    else if (startPoint.x < destination.x && startPoint.y > destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = startPoint.y - destination.y;

        state = 2;
        direction = true;
        Entity::setScale(Vector2f(1, 1));
        //mouthPiece.setPosition(Vector2f(Fish::getPosition().x + 7, Fish::getPosition().y - 3));
    }
    else if (startPoint.x > destination.x && startPoint.y < destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = destination.y - startPoint.y;

        state = 3;
        direction = false;
        Entity::setScale(Vector2f(-1, 1));
        //mouthPiece.setPosition(Vector2f(Fish::getPosition().x - 13, Fish::getPosition().y - 3));
    }
    else if (startPoint.x > destination.x && startPoint.y > destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = startPoint.y - destination.y;
        state = 4;
        direction = false;
        Entity::setScale(Vector2f(-1, 1));
        //mouthPiece.setPosition(Vector2f(Fish::getPosition().x - 13, Fish::getPosition().y - 3));
    }

    startDistanceX = distanceX;
    startDistanceY = distanceY;
}

void Entity::Reset()
{
    startPoint = Entity::reachPosition();
    destination = Entity::getRandomPos();
    setDirection();
    idle = getRandomNumber(3,5);
}

const sf::Vector2f Entity::getRandomPos()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, screenWidth); 
    std::uniform_int_distribution<std::mt19937::result_type> dist7(0, screenHeight);
    return Vector2f(dist6(rng), dist7(rng));
}

const int Entity::getRandomNumber(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max); // distribution in range [1, 6]

    return dist6(rng);
}

const sf::Vector2f Entity::getStartPoint()
{
    return startPoint;
}
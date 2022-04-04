// carnivore.cpp
#include "carnivore.h"
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
float distanceX, distanceY;
int state;
bool direction;

//Getting Carnivore and giving a start point and a random destination.
Carnivore::Carnivore() : speed(100), Entity(IntRect(Vector2(0, 0), Vector2(32, 32)))
{
	setOrigin(Vector2f(16, 16));
	startPoint = Carnivore::getRandomPos();
	Carnivore::setPosition(startPoint);
	destination = Carnivore::getRandomPos();
	setDirection();
}

//Function to give a random position to the carnivore.
const Vector2f Carnivore::getRandomPos()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, screenWidth); // distribution in range [1, 6]
	std::uniform_int_distribution<std::mt19937::result_type> dist7(0, screenHeight);
	return Vector2f(dist6(rng), dist7(rng));

}

//Updating the position of the Carnivore with delta time.
void Carnivore::Update(float& dt)
{
    Entity::Update(dt);


    if (distanceX > 0 && distanceY > 0)
    {
        switch (state)
        {
        case 1:
            Carnivore::move(Vector2f(speed * dt, speed * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 2:
            Carnivore::move(Vector2f(speed * dt, (-speed) * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 3:
            Carnivore::move(Vector2f((-speed) * dt, speed * dt));
            distanceX = distanceX - (speed * dt);
            distanceY = distanceY - (speed * dt);
            break;
        case 4:
            Carnivore::move(Vector2f((-speed) * dt, (-speed) * dt));
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



//The reset of the carnivore
void Carnivore::Reset()
{
    startPoint = Carnivore::reachPosition();
    destination = Carnivore::getRandomPos();
    setDirection();
}




//Setting the direction to the carnivore
void Carnivore::setDirection()
{
    if (startPoint.x < destination.x && startPoint.y < destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = destination.y - startPoint.y;

        state = 1;
        direction = true;
        Carnivore::setScale(Vector2f(1, 1));
    }
    else if (startPoint.x < destination.x && startPoint.y > destination.y)
    {
        distanceX = destination.x - startPoint.x;
        distanceY = startPoint.y - destination.y;

        state = 2;
        direction = true;
        Carnivore::setScale(Vector2f(1, 1));
    }
    else if (startPoint.x > destination.x && startPoint.y < destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = destination.y - startPoint.y;

        state = 3;
        direction = false;
        Carnivore::setScale(Vector2f(-1, 1));
    }
    else if (startPoint.x > destination.x && startPoint.y > destination.y)
    {
        distanceX = startPoint.x - destination.x;
        distanceY = startPoint.y - destination.y;

        state = 4;
        direction = false;
        Carnivore::setScale(Vector2f(-1, 1));
    }
}
// manager.cpp

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "manager.h"
#include "game.h"
#include "fish.h"

using namespace std;
using namespace sf;


//Temp audio



//Generate crosshair
Crosshair* crosshair = new Crosshair();



const Keyboard::Key controls[11] =
{
    Keyboard::Num0,
    Keyboard::Num1, Keyboard::Num2,
    Keyboard::Num3, Keyboard::Num4,
    Keyboard::Num5, Keyboard::Num6,
    Keyboard::Num7, Keyboard::Num8,
    Keyboard::Num9, Keyboard::Space
};


Manager::Manager() : chipsScore(100)
{
    font.loadFromFile("res/SupermercadoOne-Regular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setString(std::to_string(chipsScore));
    scoreText.setPosition(Vector2f(screenWidth - 100, 20));
    Fish* fish = new Fish();
    fishes.push_back(fish);
    
    
}

void Manager::Update(float& dt)
{
    crosshair->Update(dt);


    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if (buyTimer >= 0.1)
        {
            if ((chipsScore - 100) >= 0)
            {
                Fish* fish = new Fish();
                fishes.push_back(fish);
                addChips(-100);
                scoreText.setString(std::to_string(chipsScore));
            }
            buyTimer = 0;
        }
    }
    buyTimer += dt;

    if (Keyboard::isKeyPressed(controls[10]))
    {
        if (feedTimer >= 0.1)
        {
            Consumable* food = new Consumable(false, crosshair->getPosition(), 64, 0, 0);
            foodObjects.push_back(food);
            feedTimer = 0;
        }
    }
    feedTimer += dt;

    for (auto& fish : fishes)
    {
        if (fish->getCoinCounter() < 0 && fish->getSizeGrowth() > 0)
        {
            if (fish->getSizeGrowth() == 2)
            {
                fish->resetCoinCounter();
                Consumable* coin = new Consumable(true, fish->reachPosition(), 96, 0, 20);
                currencyObjects.push_back(coin);
            }
            else if (fish->getSizeGrowth() == 1)
            {
                fish->resetCoinCounter();
                Consumable* coin = new Consumable(true, fish->reachPosition(), 96, 0, 10);
                currencyObjects.push_back(coin);
            }
        }
        if (fish->isHungry == false)
        {
            fish->Update(dt);
        }
        else
        {
            if (fish->getHungerTimer() > -15)
            {
                fish->setHungryFish();
                if (foodObjects.size() > 0)
                {
                    moveToClosestPoint(*fish);
                }
                for (int i = foodObjects.size() - 1; i >= 0; i--)
                {
                    if (fish->getMouth().getGlobalBounds().findIntersection(foodObjects[i]->getGlobalBounds()))
                    {

                        if (fish->isHungry == true)
                        {
                            fish->fishReset();
                            fish->giveXP();
                            fish->setFullFish();
                            delete foodObjects[i];
                            foodObjects.erase(foodObjects.begin() + i);
                            fish->playGulp();
                        }

                        if (fish->getXP() > 40)
                        {
                            if (fish->getXP() > 100)
                            {
                                fish->Grow2();
                                fish->setSizeGrowth(2);
                            }
                            else
                            {
                                fish->Grow1();
                                fish->setSizeGrowth(1);
                            }

                        }



                    }
                }
            }
            else if (fish->getHungerTimer() < -15)
            {
                fish->_fordeletion = true;
            }
            fish->Update(dt);
        }
    }


    for (int i = foodObjects.size() - 1; i >= 0; i--)
    {
        foodObjects[i]->Update(dt);
        if (foodObjects[i]->_fordeletion)
        {
            delete foodObjects[i];
            foodObjects.erase(foodObjects.begin() + i);
        }
    }

    for (int i = currencyObjects.size() - 1; i >= 0; i--)
    {
        currencyObjects[i]->Update(dt);
        if (currencyObjects[i]->_fordeletion)
        {
            delete currencyObjects[i];
            currencyObjects.erase(currencyObjects.begin() + i);
        }
        else if (crosshair->getGlobalBounds().findIntersection(currencyObjects[i]->getGlobalBounds()))
        {
            addChips(currencyObjects[i]->getValue());
            delete currencyObjects[i];
            currencyObjects.erase(currencyObjects.begin() + i);
        }
    }

    for (int i = fishes.size() - 1; i >= 0; i--)
    {
        if (fishes[i]->_fordeletion == true)
        {
            delete fishes[i];
            fishes.erase(fishes.begin() + i);
        }
    }

}

void Manager::changeScore(int a)
{
    chipsScore -= a;
    scoreText.setString(std::to_string(chipsScore));
}

sf::Text Manager::getText()
{
    return Manager::scoreText;
}

std::vector<Fish*> Manager::getFish()
{
    return fishes;
}

float Manager::closestPoint(Vector2f obj1, Vector2f obj2)
{
    float sum1 = obj1.x + obj1.y;
    float sum2 = obj2.x + obj2.y;
    if (sum1 > sum2)
    {
        return sum1 - sum2;
    }
    else
    {
        return sum2 - sum1;
    }
}

void Manager::moveToClosestPoint(Fish& fish)
{
    float smallestDiff = 2401;
    for (int i = 0; i < foodObjects.size(); i++)
    {
        
        if (smallestDiff > Manager::closestPoint(fish.reachPosition(), foodObjects[i]->reachPosition()))
        {
            fish.destination = foodObjects[i]->reachPosition();
            smallestDiff = Manager::closestPoint(fish.reachPosition(), foodObjects[i]->reachPosition());
            //cout << smallestDiff << endl;
        }
    }
    fish.startPoint = fish.reachPosition();
    fish.setBothDirection();
    fish.SpeedUP();
}

void Manager::Render(RenderWindow& window)
{
    for (const auto fish : fishes)
    {
        window.draw(*fish);
        window.draw(fish->getMouth());
    }
    
    window.draw(*crosshair);
    window.draw(scoreText);
    //window.draw(*fish);
    for (const auto& consumable : foodObjects)
    {
        window.draw(*consumable);
    }
    for (auto& coin : currencyObjects)
    {
        window.draw(*coin);
    }
}

int Manager::getChips()
{
    return chipsScore;
}

void Manager::setChips(int chips)
{
    Manager::chipsScore = chips;
}

void Manager::addChips(int chips)
{
    Manager::chipsScore += chips;
}
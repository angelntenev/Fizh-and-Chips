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
    //spritesheet.loadFromFile("res/Fish.png");
    //fish->setTexture(spritesheet);
    Fish* fish = new Fish();
    fishes.push_back(fish);
    
}

void Manager::Update(float& dt)
{
    crosshair->Update(dt);


    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if ((chipsScore - 10) > 0)
        {
            Fish* fish = new Fish();
            fishes.push_back(fish);
        }
    }

    if (Keyboard::isKeyPressed(controls[10]))
    {
        Consumable* food = new Consumable(true, crosshair->getPosition());
        foodObjects.push_back(food);
    }

    for (auto& fish : fishes)
    {
        fish->Update(dt);
    }
    cout << fishes.size() << " ";


    for (int i = foodObjects.size() - 1; i >= 0; i--)
    {
        foodObjects[i]->Update(dt);
        if (foodObjects[i]->_fordeletion)
        {
            delete foodObjects[i];
            foodObjects.erase(foodObjects.begin() + i);
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


void Manager::Render(RenderWindow& window)
{
    for (const auto fish : fishes)
    {
        window.draw(*fish);
    }
    
    window.draw(*crosshair);
    window.draw(scoreText);
    //window.draw(*fish);
    for (const auto& consumable : foodObjects)
    {
        window.draw(*consumable);
    }
}
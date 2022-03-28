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




const Keyboard::Key controls[10] =
{
    Keyboard::Num0,
    Keyboard::Num1, Keyboard::Num2,
    Keyboard::Num3, Keyboard::Num4,
    Keyboard::Num5, Keyboard::Num6,
    Keyboard::Num7, Keyboard::Num8,
    Keyboard::Num9
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
    scoreText.setString(std::to_string(chipsScore));
    if (Keyboard::isKeyPressed(controls[1]))
    {
        if ((chipsScore - 10) > 0)
        {
            Fish* fish = new Fish();
            fishes.push_back(fish);
        }
    }

    for (auto& fish : fishes)
    {
        fish->Update(dt);
    }
    cout << fishes.size() << " ";
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

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include "crosshair.h"
#include "entity.h"
#include "game.h"
#include "fish.h"
#include "carnivore.h"

using namespace std;
using namespace sf;

//Size of screen
const Vector2f screenVec = Vector2f(screenWidth, screenHeight);


//Generate crosshair
sf::Texture spritesheet;
Crosshair* crosshair = new Crosshair();

sf::Texture spritesheet2;

//Generate Fish
std::vector<Fish*> fishes;
Fish* fish = new Fish();


//Generate Carnivore
std::vector<Carnivore*> carnivores;
Carnivore* carnivore = new Carnivore();

void Load()
{
    spritesheet.loadFromFile("res/Crosshair.png");
    spritesheet2.loadFromFile("res/Fish.png");
    
    //fish->setTexture(spritesheet2);

    fish->setTexture(spritesheet2);
    fishes.push_back(fish);

    carnivore->setTexture(spritesheet2);
    carnivores.push_back(carnivore);
}

void Reset()
{

}

void Update(RenderWindow& window)
{
    static Clock clock;
    float dt = clock.restart().asSeconds();
    

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }



    crosshair->Update(dt);
    for (auto& fish : fishes)
    {
        fish->Update(dt);
    }
    //cout << fish->getRandomPos().x << endl;


    for (auto& carnivore : carnivores)
    {
        carnivore->Update(dt);
    }

}

void Render(RenderWindow& window)
{
    window.draw(*crosshair);
    for (const auto& fish : fishes)
    {
        window.draw(*fish);
    }

    for (const auto& carnivore : carnivores)
    {
        window.draw(*carnivore);
    }
}

int main()
{
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Fizh & Chips");
    Load();
    while (window.isOpen())
    {
        window.clear(sf::Color::Blue);
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}





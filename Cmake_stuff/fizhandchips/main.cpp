#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include "crosshair.h"
#include "entity.h"
#include "game.h"
#include "fish.h"
#include "manager.h"
using namespace std;
using namespace sf;

//Size of screen
const Vector2f screenVec = Vector2f(screenWidth, screenHeight);


//Generate crosshair
sf::Texture spritesheet;
Crosshair* crosshair = new Crosshair();


//Generate manager
Manager* gameManager = new Manager();



//Fish* fish1 = new Fish();

void Load()
{
    spritesheet.loadFromFile("res/Crosshair.png");
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


    gameManager->Update(dt);
    crosshair->Update(dt);
    //fish1->Update(dt);

}

void Render(RenderWindow& window)
{
    
    for (const auto fish : gameManager->getFish())
    {
        window.draw(*fish);
    }
    auto p = gameManager->getText();
    window.draw(p);
    //window.draw(*fish1);
    window.draw(*crosshair);
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





#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include <string>
#include "crosshair.h"
#include "entity.h"
#include "game.h"
#include "fish.h"
//#include "carnivore.h"
#include "manager.h"
using namespace std;
using namespace sf;

//Size of screen
const Vector2f screenVec = Vector2f(screenWidth, screenHeight);


//Generate crosshair
sf::Texture spritesheet;
sf::Texture spritesheetShark;
sf::Texture spritesheetBossEnemy;
sf::Texture shootTexture;
sf::Texture target;
sf::Texture spritesheetBackground;
sf::Texture spritesheetSeaWeed;
sf::Texture spritesheetRock;

//Generate manager
shared_ptr<Manager> gameManager = make_shared<Manager>();




//Fish* fish1 = new Fish();

void Load()
{
    spritesheet.loadFromFile("res/Crosshair.png");
    spritesheetShark.loadFromFile("res/Shark.png");
    spritesheetBossEnemy.loadFromFile("res/BossEnemy.png");
    shootTexture.loadFromFile("res/Attack.png");
    spritesheetBackground.loadFromFile("res/fizhBackground.png");
    target.loadFromFile("res/fizhBackground.png");
    spritesheetSeaWeed.loadFromFile("res/seaWEED.png");
    spritesheetRock.loadFromFile("res/1Rock.png");

   
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

    //fish1->Update(dt);

}

void Render(RenderWindow& window)
{
    
    gameManager->Render(window);

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





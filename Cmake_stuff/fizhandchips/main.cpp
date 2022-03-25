#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
using namespace sf;

//Size of screen
const float screenWidth = 800.f, screenHeight = 600.f;
const Vector2f screenVec = Vector2f(screenWidth, screenHeight);
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Fizh & Chips");


//Player Controls for moving crosshair
const Keyboard::Key controls[4] =
{
    Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D
};

void Load()
{

}

void Reset()
{

}

void Update(RenderWindow& window)
{

}

void Render(RenderWindow& window)
{
    
}

int main()
{
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Fizh & Chips");
    Load();
    while (window.isOpen())
    {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}
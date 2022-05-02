//menu.cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "menu.h"
#include "game.h"


Menu::Menu()
{
    setTexture(menuBackground);
    int _screenWidth = (int)screenWidth, _screenHeight = (int)screenHeight;
    setTextureRect(IntRect(Vector2(0, 0), Vector2(_screenWidth, _screenHeight)));
    setOrigin(Vector2f(screenWidth/2, screenHeight/2));
    setPosition(Vector2f(screenWidth / 2, screenHeight / 2));
    font.loadFromFile("res/SupermercadoOne-Regular.ttf");

    playButton.setTexture(menuButton);
    playButton.setTextureRect(IntRect(Vector2(0, 0), Vector2(200,100)));
    playButton.setOrigin(Vector2f(100, 50));
    playButton.setPosition(Vector2f(screenWidth / 2, screenHeight / 4));
    playText.setFont(font);
    playText.setString("Play game");
    playText.setCharacterSize(32);
    playText.setPosition(Vector2f((screenWidth / 2) - 75, (screenHeight / 4) - 30));

    restartButton.setTexture(menuButton);
    restartButton.setTextureRect(IntRect(Vector2(0, 0), Vector2(200, 100)));
    restartButton.setOrigin(Vector2f(100, 50));
    restartButton.setPosition(Vector2f(screenWidth / 2, playButton.getPosition().y + 200));
    restartText.setFont(font);
    restartText.setString("Restart Game");
    restartText.setCharacterSize(32);
    restartText.setPosition(Vector2f((screenWidth / 2) - 90, playButton.getPosition().y + 170));


}

void Menu::Render(sf::RenderWindow& window)
{
    window.draw(playButton);
    window.draw(restartButton);
    window.draw(playText);
    window.draw(restartText);
}

void Menu::Update(float& dt)
{
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        if (crosshair->getGlobalBounds().findIntersection(playButton.getGlobalBounds()))
        {
            setActive(false);
        }
        else if (crosshair->getGlobalBounds().findIntersection(restartButton.getGlobalBounds()))
        {
            setActive(false);
            reset = true;
        }
    }
}
bool Menu::getActive()
{
    return isActive;
}

void Menu::setActive(bool _active)
{
    isActive = _active;
}
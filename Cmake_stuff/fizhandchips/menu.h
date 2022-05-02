//menu.h
#pragma once
#include "entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
using namespace std;
using namespace sf;


class Menu : public Sprite
{
private:
	Sprite playButton;
	Sprite restartButton;
	bool isActive = true;
	sf::Text playText;
	sf::Text restartText;
	sf::Font font;
public:
	Menu();
	void Update(float& dt);
	void Render(sf::RenderWindow& window);
	void restartGame();
	void goBackToGame();
	bool getActive();
	void setActive(bool _active);
};
//game.h
#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "crosshair.h"
#include "fish.h"

extern sf::Texture spritesheet;
extern sf::Texture spritesheetShark;
extern sf::Texture spritesheetBossEnemy;
extern sf::Texture spritesheetBackground;
extern sf::Texture spritesheetSeaWeed;
extern sf::Texture spritesheetRock;
extern sf::Texture shootTexture;
extern sf::Texture target;
extern sf::Texture menuBackground;
extern sf::Texture menuButton;
extern sf::Texture dashBoard;
extern bool noHunger;
extern Crosshair* crosshair;
extern bool pause;
extern bool reset;
const float screenWidth = 1600.f, screenHeight = 800.f;

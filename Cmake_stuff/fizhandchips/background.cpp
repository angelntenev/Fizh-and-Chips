// background.cpp
#include "fish.h"
#include "game.h"
#include "background.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;





Background::Background()
{

    int tempWidth = (int)screenWidth;
    int tempHeight = (int)screenHeight;
    setOrigin(Vector2f(screenWidth/2, screenHeight/2));
    setPosition(Vector2f(screenWidth / 2, screenHeight / 2));
    
     setTexture(spritesheetBackground);
     setTextureRect(IntRect(Vector2(0, 0), Vector2(tempWidth, tempHeight)));

     

     seaWeed.setScale(Vector2f(-2, 2));


     decorations.push_back(seaWeed.getDecoration(Vector2f(240, 650), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(200, 650), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(200, 650), seaWeed, true));


     //3 seaweed and 1 rock
     decorations.push_back(seaWeed.getDecoration(Vector2f(360, 480), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(380, 480), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(400, 480), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(400, 480), seaWeed, true));
    

    
     //3 seaweed and 3 rocks
     decorations.push_back(seaWeed.getDecoration(Vector2f(550, 750), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(590, 750), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(620, 750), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(550, 750), seaWeed, true));
     decorations.push_back(seaWeed.getDecoration(Vector2f(590, 750), seaWeed, true));
     decorations.push_back(seaWeed.getDecoration(Vector2f(620, 750), seaWeed, true));



     //OnlySeaWeed
     decorations.push_back(seaWeed.getDecoration(Vector2f(900, 770), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(920, 770), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(940, 770), seaWeed, false));

   
     //2 rocks 2 seaweeds separated
     decorations.push_back(seaWeed.getDecoration(Vector2f(1080, 600), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1140, 600), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1080, 600), seaWeed, true));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1120, 600), seaWeed, true));



     //2 rocks and 2 seaweed
     decorations.push_back(seaWeed.getDecoration(Vector2f(1500, 680), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1520, 680), seaWeed, false));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1500, 680), seaWeed, true));
     decorations.push_back(seaWeed.getDecoration(Vector2f(1520, 680), seaWeed, true));


}





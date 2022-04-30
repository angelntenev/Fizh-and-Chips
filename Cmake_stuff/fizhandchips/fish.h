// fish.h
#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

using namespace sf;

class Fish : public Entity
{
private:
	int size = 0;
	int xp = 0;
	float speed;
	bool direction;
	float hungerTimer = 20;
	float coinCounter = 3;
	RectangleShape mouthPiece;
	float scaleX = 1, scaleY = 1;
	SoundBuffer buffer;
	Sound sound;
public:
	Fish();
	void Update(float& dt) override;
	RectangleShape getMouth();
	void setBothDirection();
	void moveTowardsWithMouth(sf::Vector2f& destination, float& speed, float& dt);
	void fishReset();
	void resetHungerTimer();
	void SpeedUP();
	bool isHungry = false;
	float getCoinCounter();
	void resetCoinCounter();
	int getSizeGrowth();
	void setSizeGrowth(int _size);
	int getXP();
	void giveXP();
	void Grow1();
	void Grow2();
	void setHungryFish();
	void setFullFish();
	void setDeadFish();
	void sinkToDeath();
	void playGulp();
	void resetSpeed();
	void setSharkSprite();
	float getHungerTimer();
};
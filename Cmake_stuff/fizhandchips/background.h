// background.h
#pragma once
#include "entity.h"
#include "decorationSprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

using namespace sf;
class Background : public Sprite
{

private:
	
	Sprite rock;
	void setRockSprite();
	DecorationSprite seaWeed = new DecorationSprite(false);
public:
	Background();
	std::vector<DecorationSprite> decorations;
};



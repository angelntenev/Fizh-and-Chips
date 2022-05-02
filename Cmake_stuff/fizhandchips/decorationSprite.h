#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
using namespace sf;

class DecorationSprite : public Sprite
{
private:

	bool active = false;
public:
	std::vector<DecorationSprite> allDecorations(std::vector<DecorationSprite> _decorations);
	DecorationSprite(bool rockORseaweed);
	DecorationSprite getDecoration(Vector2f loc, DecorationSprite decorationSprite, bool isRockOrSeaweed);
	bool getActive();

};


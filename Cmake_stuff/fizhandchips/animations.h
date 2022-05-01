#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

using namespace sf;

class Anim : public Entity
{
private:
	Clock clock;
	bool shot = false;
public:
	void Update(float& dt) override;
	Anim(Vector2f loc);
	void setLoc(Vector2f loc);
	void resetShot();
};
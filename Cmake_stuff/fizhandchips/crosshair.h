// crosshair.h
#pragma once
#include "entity.h"
#include <SFML/Window/Keyboard.hpp>

class Crosshair : public Entity
{
private:
	float _speed;
public:
	Crosshair();
	void Update(float& dt) override;
	Crosshair getCrosshair();
};
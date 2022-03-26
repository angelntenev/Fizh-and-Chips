// crosshair.h
#pragma once
#include "entity.h"

class Crosshair : public Entity
{
private:
	float _speed;
public:
	Crosshair();
	void Update(float& dt) override;

};
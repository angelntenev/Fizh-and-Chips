//carnivore.h
#pragma once
#include"entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Carnivore : public Entity
{
private:
	float speed;
	sf::Vector2f destination;
	const sf::Vector2f getRandomPos();

public:
	Carnivore();
	void Update(float& dt) override;
	void Reset();
	void setDirection();
};
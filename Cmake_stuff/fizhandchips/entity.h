// entity.h
#pragma once

#include <SFML/Graphics.hpp>


class Entity : public sf::Sprite{
protected:
	sf::IntRect _sprite;
	//Entity(std::unique_ptr<sf::RectangleShape> shp);
public:
	explicit Entity(sf::IntRect ir);
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(float& dt);

	const sf::Vector2f reachPosition();
};
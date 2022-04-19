// entity.h
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;


class Entity : public sf::Sprite{
protected:
	sf::IntRect _sprite;
	
	//Entity(std::unique_ptr<sf::RectangleShape> shp);
	bool _alive;       // should be updated
	bool _visible;     // should be rendered

	float distanceX, distanceY;
	float startDistanceX, startDistanceY;
	int state;
	float idle = 5;
	bool direction;
	const sf::Vector2f getRandomPos();
	const sf::Vector2f getStartPoint();
public:
	bool _fordeletion = false; // should be deleted
	explicit Entity(sf::IntRect ir);
	Entity() = delete;
	virtual ~Entity() = default;
	virtual void Update(float& dt);
	void Reset();
	void setDirection();
	void moveTowards(sf::Vector2f& destination, float& speed, float& dt);
	const int getRandomNumber(int min, int max);
	const sf::Vector2f reachPosition();
	sf::Vector2f startPoint;
	sf::Vector2f destination;
};
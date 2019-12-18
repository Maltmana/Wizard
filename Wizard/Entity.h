#pragma once
#include "SFML/system.hpp"
#include "SFML/Graphics.hpp"

#include <limits>

#define NULLENTITY 0

class Entity
{
public:
	void makeEntity()
	{
		ID = statID;
		statID++;
	}

	void nullify()
	{
		ID = NULLENTITY;
	}

	void update()
	{
			position += velocity;
	}

	// fundamental
	unsigned long long ID{ NULLENTITY };
	sf::Vector2f position{ 0.f,0.f };
	sf::Vector2f velocity{ 0.f, 0.f };

	// movers
	float speed{ 0 };

	//graphics
	sf::Color color{ sf::Color::Magenta };

private:
	static unsigned long statID;
};


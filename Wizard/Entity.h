#pragma once
#include "SFML/system.hpp"
#include "SFML/Graphics.hpp"

class Entity
{
public:
	Entity()
		: ID{statID}
	{
		statID++;
	}

	void update()
	{
		position += velocity;
	}

	// fundamental
	unsigned int ID;
	sf::Vector2f position{ 0.f,0.f };
	sf::Vector2f velocity{ 0.f, 0.f };

	// movers
	float speed{ 0 };

	//graphics
	sf::Color color{ sf::Color::Magenta };

private:
	static unsigned int statID;
};


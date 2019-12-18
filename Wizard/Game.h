#pragma once
#include <vector>
#include "Entity.h"
#include "SystemWindow.h"

class Game
{
public:
	void init();
	void gameLoop();

	std::vector<Entity> projectiles;
	Entity player;
	std::vector<Entity> entities;

	// vector of vector of entities.

	// memory management alg
	// reserve 10mb.
	// new entities get pushed back
	// when an entity has reached death condition, it will be marked dead.
	// when entity reaches delete condition, it will be cleared from memory on the next update.
	// open memory slots will be marked and new entities will be pushed back into them.

	SystemWindow systemWindow;

	sf::CircleShape shape;

private:
	void update();
};


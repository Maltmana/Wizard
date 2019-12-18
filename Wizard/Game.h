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


	// memory management alg
	// "make space"
	// reserve 10mb.
	// new entities get pushed back
	// when an entity has reached death condition, it will be marked dead.
	// when entity reaches delete condition, it will be cleared from memory on the next update.
	// open memory slots will be marked and new entities will be pushed back into them.

	// "rewrite and recycle"
	// if entity is a particle:
	// resize vector to particle limit.
	// when particle reaches delete condition it is marked as rewritable
	// when call to create new particle comes, new particle is written over first rewritable marked particle.

	// should ID = index or should they be seperate? why not have both?

	SystemWindow systemWindow;

	sf::CircleShape shape;



private:
	void update();
	void render();
};


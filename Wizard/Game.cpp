#include "Game.h"

#include "RNG.h"


#include "WLib.h"

#include <SFML/Graphics.hpp>

#include <bitset>
#include <cmath>

RNG rng;

void Game::init()
{

	entities.resize(100);
	
	for (auto & entity : entities)
	{
		entity.color = sf::Color::Blue;
		entity.position = player.position + sf::Vector2f{rng.rand<float>(-100, 100), rng.rand<float>(-100, 100) };
		entity.velocity = sf::Vector2f{ rng.rand<float>(-0.5f, 0.5f), rng.rand<float>(-0.5f, 0.5f) };
		entity.makeEntity();
	}
	
	player.position = { 0.f, 0.f };
	player.speed = { 25 };
	player.color = sf::Color::Green;

	shape.setRadius(3.f);

	shape.setFillColor(sf::Color::Green);
	shape.setOrigin({ shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2 });
}

//////////////////////////////////////// GAME LOOP
void Game::gameLoop()
{
	while (systemWindow.window.isOpen())
	{
		update();
		render();
	}
}

void Game::update()
{
	systemWindow.update();

	//////////////////// Useful Data
	sf::Vector2f playerMouseDifferenceVector{ player.position - window_to_world(systemWindow.mousePosition, systemWindow.window) };
	sf::Vector2f normalizedPlayerMouseDifferenceVector{ normalize(playerMouseDifferenceVector) };


	//////////////////// Controls
	////////// Keyboard controls
	// fire projectile
	if (systemWindow.keysPressed[sf::Keyboard::Num1])
	{
		entities.emplace_back();

		//
		projectiles.emplace_back();
		projectiles.back().position = player.position;
		projectiles.back().speed = 0.1f;
		projectiles.back().velocity = { -(normalizedPlayerMouseDifferenceVector * projectiles.back().speed) };

		projectiles.back().color = sf::Color::Red;
	}

	if (systemWindow.keysPressed[sf::Keyboard::Num2])
	{
		for (auto& entity : entities)
		{
			entity.position = player.position + sf::Vector2f{ rng.rand<float>(-100, 100), rng.rand<float>(-100, 100) };
			entity.velocity = sf::Vector2f{ rng.rand<float>(-0.5f, 0.5f), rng.rand<float>(-0.5f, 0.5f) };
		}
	}

	if (systemWindow.keysHeld[sf::Keyboard::Escape])
	{
		systemWindow.window.close();
	}

	////////// Mouse controls
	if (systemWindow.mouseHeld[0])
	{

		sf::Vector2f playerMouseDifferenceVector{ player.position - window_to_world(systemWindow.mousePosition, systemWindow.window) };

		player.position -= normalize(playerMouseDifferenceVector) * (player.speed / 1000);
	}

	if (systemWindow.mouseHeld[1])
	{

		sf::Vector2f playerMouseDifferenceVector{ player.position - window_to_world(systemWindow.mousePosition, systemWindow.window) };

		player.position += normalize(playerMouseDifferenceVector) * (player.speed / 1000);
	}

	//////////////////////////////////////// UPDATING
	player.update();
	for (auto& proj : projectiles)
	{
		proj.update();
	}

	for (auto& entity : entities)
	{
		if (entity.ID)
		{
			entity.update();
		}
	}

	
}

void Game::render()
{
	systemWindow.window.clear();

	// render player
	shape.setPosition(world_to_window(player.position, systemWindow.window));
	shape.setFillColor(player.color);
	systemWindow.window.draw(shape);

	// render projectiles
	for (auto& proj : projectiles)
	{
		shape.setPosition(world_to_window(proj.position, systemWindow.window));
		shape.setFillColor(proj.color);
		systemWindow.window.draw(shape);
	}

	// render entities
	for (auto& entity : entities)
	{
		if (entity.ID)
		{
			shape.setPosition(world_to_window(entity.position, systemWindow.window));
			shape.setFillColor(entity.color);
			systemWindow.window.draw(shape);
		}
	}

	systemWindow.window.display();
}
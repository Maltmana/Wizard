#include "Game.h"




#include "WLib.h"

#include <SFML/Graphics.hpp>

#include <bitset>
#include <cmath>



void Game::init()
{
	
	player.position = { 0.f, 0.f };
	player.speed = { 100 };
	player.color = sf::Color::Green;

	shape.setRadius(33.f);

	shape.setFillColor(sf::Color::Green);
	shape.setOrigin({ shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2 });
}

//////////////////////////////////////// GAME LOOP
void Game::gameLoop()
{
	while (systemWindow.window.isOpen())
	{
		update();
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
	if (systemWindow.keysPressed[sf::Keyboard::Num1])
	{
		projectiles.emplace_back();
		projectiles.back().position = player.position;
		projectiles.back().speed = 0.1f;
		//
		projectiles.back().velocity = { -(normalizedPlayerMouseDifferenceVector * projectiles.back().speed) };
		//

		projectiles.back().color = sf::Color::Red;
	}

	if (systemWindow.keysPressed[sf::Keyboard::Num2])
	{
		projectiles.emplace_back();
		projectiles.back().position = player.position;
		projectiles.back().velocity = { 0.1f, 0.1f };
		projectiles.back().color = sf::Color::Magenta;
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

	////////// Mouse controls
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

	//////////////////////////////////////// RENDERING
	// clear
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

	// display
	systemWindow.window.display();
}
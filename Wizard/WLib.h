#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

float magnitude(sf::Vector2f vector);


sf::Vector2f normalize(sf::Vector2f vector);

sf::Vector2f window_to_world(sf::Vector2f coordinates, sf::RenderWindow const& window);

sf::Vector2f world_to_window(sf::Vector2f coordinates, sf::RenderWindow const& window);
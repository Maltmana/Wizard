#pragma once
#include <SFML/Graphics.hpp>
#include <bitset>

class SystemWindow
{
public: 
	void update();

	// window
	sf::RenderWindow window{ sf::VideoMode{1000u, 1000u }, ""
};

	// keyboard
	std::bitset<sf::Keyboard::KeyCount> keysPressed;
	std::bitset<sf::Keyboard::KeyCount> keysHeld;
	std::bitset<sf::Keyboard::KeyCount> keysReleased;

	// mouse
	sf::Vector2f mousePosition;
	std::bitset<sf::Mouse::ButtonCount> mousePressed;
	std::bitset<sf::Mouse::ButtonCount> mouseHeld;
	std::bitset<sf::Mouse::ButtonCount> mouseReleased;
};


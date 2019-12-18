#include "WLib.h"

float magnitude(sf::Vector2f vector)
{
	return sqrtf((vector.x * vector.x) + (vector.y * vector.y));
}

sf::Vector2f normalize(sf::Vector2f vector)
{
	float vecMagnitude{ magnitude(vector) };
	return vector / vecMagnitude;
}

sf::Vector2f window_to_world(sf::Vector2f coordinates, sf::RenderWindow const& window)
{
	sf::Vector2f ret;
	ret.x = coordinates.x - (window.getSize().x / 2);
	ret.y = -coordinates.y + (window.getSize().y / 2);
	return ret;
	//player.position = { (float)sf::Mouse::getPosition(window).x - (windowWidth / 2), -(float)sf::Mouse::getPosition(window).y + (windowHeight / 2) };
}

sf::Vector2f world_to_window(sf::Vector2f coordinates, sf::RenderWindow const& window)
{
	sf::Vector2f ret;
	ret.x = coordinates.x + (window.getSize().x / 2);
	ret.y = -coordinates.y + (window.getSize().y / 2);
	return ret;
}

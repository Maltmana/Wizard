#include <SFML/Graphics.hpp>

#include <bitset>
#include <cmath>



//////////////////////////////////////// VECTOR MATH

float magnitude(sf::Vector2f vector)
{
	return sqrtf((vector.x * vector.x) + (vector.y * vector.y));
}


sf::Vector2f normalize(sf::Vector2f vector)
{
	float vecMagnitude{ magnitude(vector) };
	return vector / vecMagnitude;
}




//////////////////////////////////////// WINDOW TO WORLD CONVERTING
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


//////////////////////////////////////// GAME DATA
class Player
{
public:
	sf::Vector2f position;
	float speed;
private:

};


int main()
{
	//////////////////////////////////////// INIT
	////////// INIT WINDOW
	sf::Vector2i windowDimensions{ 1000,1000 };
	sf::RenderWindow window(sf::VideoMode(windowDimensions.x, windowDimensions.y), "SFML works!");

	////////// INIT INPUT DATA
	std::bitset<sf::Keyboard::KeyCount> keysPressed;
	std::bitset<sf::Keyboard::KeyCount> keysHeld;
	std::bitset<sf::Keyboard::KeyCount> keysReleased;

	sf::Vector2f mousePosition;
	std::bitset<sf::Mouse::ButtonCount> mousePressed;
	std::bitset<sf::Mouse::ButtonCount> mouseHeld;
	std::bitset<sf::Mouse::ButtonCount> mouseReleased;

	////////// INIT GRAPHICS DATA
	//shape
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setOrigin({100.0f, 100.0f});

	////////// INIT GAME DATA
	// player
	Player player;
	player.position = { 0.f, 0.f };
	player.speed = { 100 };

	//////////////////////////////////////// GAME LOOP
	while (window.isOpen())
	{
		////////// INPUT
		// store mouse data
		mousePosition.x = (float)sf::Mouse::getPosition(window).x;
		mousePosition.y = (float)sf::Mouse::getPosition(window).y;

		// reset old input
		keysPressed.reset();
		keysReleased.reset();

		// handle system events
		sf::Event systemEvent;
		while (window.pollEvent(systemEvent))
		{
			switch (systemEvent.type)
			{
				// key crap
			case sf::Event::KeyPressed:
				keysPressed.set(systemEvent.key.code);
				keysHeld.set(systemEvent.key.code);
				break;
			case sf::Event::KeyReleased:
				keysReleased.set(systemEvent.key.code);
				keysHeld.set(systemEvent.key.code, 0);
				break;
				// mouse crap
			case sf::Event::MouseButtonPressed:
				mousePressed.set(systemEvent.mouseButton.button);
				mouseHeld.set(systemEvent.mouseButton.button);
				break;
			case sf::Event::MouseButtonReleased:
				mouseReleased.set(systemEvent.mouseButton.button);
				mouseHeld.set(systemEvent.mouseButton.button, 0);
				break;
				// allow window close
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		//////////////////////////////////////// GAMING
		//////////////////// Controls
		////////// Keyboard controls
		// wasd
		if (keysHeld[sf::Keyboard::W])
		{
			player.position.y++;
		}
		if (keysHeld[sf::Keyboard::A])
		{
			player.position.x--;
		}
		if (keysHeld[sf::Keyboard::S])
		{
			player.position.y--;
		}
		if (keysHeld[sf::Keyboard::D])
		{
			player.position.x++;
		}

		// esc
		if (keysHeld[sf::Keyboard::Escape])
		{
			window.close();
		}

		////////// Mouse controls
		if (mouseHeld[0])
		{
			//player.position = window_to_world(mousePosition, window);

			sf::Vector2f playerMouseDifferenceVector{ player.position - window_to_world(mousePosition, window) };

			//player.position -= playerMouseDifferenceVector * (player.speed/1000000);

			player.position -= normalize(playerMouseDifferenceVector) * (player.speed / 1000);
		}

		////////// Mouse controls
		if (mouseHeld[1])
		{
			//player.position = window_to_world(mousePosition, window);

			sf::Vector2f playerMouseDifferenceVector{ player.position - window_to_world(mousePosition, window) };

			//player.position -= playerMouseDifferenceVector * (player.speed/1000000);

			player.position += normalize(playerMouseDifferenceVector) * (player.speed / 1000);
		}


		//////////////////////////////////////// RENDERING
		// dirty flag render update
		shape.setPosition(world_to_window(player.position, window));
		//shape.setPosition({player.position.x + (windowWidth/2), -player.position.y + (windowHeight/2)});

		// render
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
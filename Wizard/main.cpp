#include <SFML/Graphics.hpp>

#include <bitset>

class Player
{
public:
	sf::Vector2f position;

private:

};


int main()
{
	//////////////////// INIT
	////////// INIT WINDOW
	int windowWidth{ 1000 };
	int windowHeight{ 1000 };
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

	////////// INIT INPUT DATA
	std::bitset<sf::Keyboard::KeyCount> keysPressed;
	std::bitset<sf::Keyboard::KeyCount> keysHeld;
	std::bitset<sf::Keyboard::KeyCount> keysReleased;

	////////// INIT GRAPHICS DATA
	//shape
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setOrigin({50.0f, 50.0f});

	////////// INIT GAME DATA
	// player
	Player player;
	player.position = { 0.f, 0.f };

	//////////////////// GAME LOOP
	while (window.isOpen())
	{
		////////// INPUT
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
				// allow window close
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		//////////////////// GAMING
		// keyboard controls
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

		// mouse controls

		//////////////////// RENDERING
		// dirty flag render update
		shape.setPosition({player.position.x + (windowWidth/2), -player.position.y + (windowHeight/2)});

		// render
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
#include "SystemWindow.h"

void SystemWindow::update()
{

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
}


#include "Game.h"



// STRATEGY:
// get a coding coach meet weekly with a list of questions
// code primarily the player entity. CODE for rushing player interaction and fun so you will stay interested.
// spend more time on headers and refactoring and making nice classes then on adding features. 
// but CODE FAST. Go from one idea quickly to another even if the next idea is dumb. just do it and do it fast with no down time.
// just make it all public for now.
// comment everything and rely entirely on your comments for navigation and finding things... That means commenting the obvious... Think of them more like nav tags.
// work on the project daily, or just delete it, because you never come back to your forgotten projects you just make new ones. and thats fine... you need the practice anyways...
// STEPPING or TIPTOEING through the code just to observe and enjoy your work.

// match SFML style.

// Ignore all stylistic and coding best practices you've learned until you understand WHY you need them. don't just DO THEM - ie don't avoid manager classes.

// don't think one second about performance.

// STYLE guidelines:
// prefer init function with generic constructor then after that header init. TREASURE default constructors.
// all public
// stuff entity class and then refactor as needed.

// TODO
// needs time and good time step
// needs particles to be destoryed at a certain time
// needs memory management

int main()
{
	Game game;
	game.init();
	game.gameLoop();
}
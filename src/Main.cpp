#include "core/Game.hpp"

// This kind of setup is need for SDL or else it will fail
int main(int argc, char* argv[])
{
	// Unused argc, argv
	(void)argc;
	(void)argv;

	// Runs the game
	Game::Instance().Run();

	return 0;
}

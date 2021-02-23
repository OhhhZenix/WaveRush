#include "core/Game.hpp"

int main(int argc, char *argv[])
{
	// Unused argc, argv
	(void)argc;
	(void)argv;

	// Runs the game
	Game::Instance().Run();

	return 0;
}

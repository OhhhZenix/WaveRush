#include "Core/Game.hpp"

int main() {
	Game* instance = new Game();
	instance->run();
	delete instance;
	return 0;
}
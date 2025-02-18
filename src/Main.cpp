#include "Core/Game.hpp"

int main() {
	Game* instance = new Game();
	instance->Run();
	delete instance;
	return 0;
}
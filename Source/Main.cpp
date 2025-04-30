#include "WaveRush/Core/ArenaAllocator.hpp"
#include "WaveRush/Core/Game.hpp"

int main() {
	ArenaAllocator allocator = ArenaAllocatorNew(1024 * 1024); // 1 MB arena
	Game* instance = GameNew(&allocator);
	GameRun(instance);
	GameDelete(instance);
	ArenaAllocatorDelete(&allocator);
	return 0;
}
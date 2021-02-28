#include "Core/Game.hpp"

unsigned allocatedHeap = 0, totalHeap = 0;
void *operator new(size_t sz)
{
	totalHeap++;
	allocatedHeap++;
	return malloc(sz);
}
void *operator new[](size_t sz)
{
	totalHeap++;
	allocatedHeap++;
	return malloc(sz);
}
void operator delete(void *p)
{
	allocatedHeap--;
	free(p);
}
void operator delete[](void *p)
{
	allocatedHeap--;
	free(p);
}

// This kind of setup is need for SDL or else it will fail
int main(int argc, char* argv[])
{
	// Unused argc, argv
	(void)argc;
	(void)argv;

	// Runs the game
	Game::Instance().Run();

	printf("Allocated Heap: %u, Total Heap: %u\n", allocatedHeap, totalHeap);
	return 0;
}

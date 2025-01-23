#include "core/allocator.h"

int main(int argc, char* argv[]) {
	ArenaAlloc(1 * 1024 * 1024);
	void* test = ArenaAlloc(1);
	ArenaCleanup();
	return 0;
}

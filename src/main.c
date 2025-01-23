#include "core/allocator.h"
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaAlloc(memInMegabytes);
	void* test = ArenaAlloc(1);
	ArenaCleanup();
	return 0;
}

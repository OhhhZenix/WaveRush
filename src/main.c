#include "core/allocator.h"
#include "core/window.h"
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaAlloc(memInMegabytes);
	WindowInit("Hello World", 640, 360);

	while (!WindowShouldClose()) {
		WindowPollEvents();
	}

	WindowCleanup();
	ArenaCleanup();

	return 0;
}

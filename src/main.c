#include "core/allocator.h"
#include "core/renderer.h"
#include "core/window.h"
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaAlloc(memInMegabytes);
	void* window = WindowInit("Hello World", 640, 360);
	RendererInit(window);

	while (!WindowShouldClose()) {
		WindowPollEvents();
		RenderBegin();
		DrawRectangle(0, 0, 32, 32);
		RenderEnd();
	}

	RendererCleanup();
	WindowCleanup();
	ArenaCleanup();

	return 0;
}

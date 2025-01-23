#include "core/allocator.h"
#include "core/renderer.h"
#include "core/window.h"
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaInit(memInMegabytes);

	WindowInit("Hello World", 640, 360);
	RendererInit();

	while (!WindowShouldClose()) {
		WindowPollEvents();
		RenderBegin((struct Color){ 0, .a = 255 });
		DrawRectangle(0, 0, 32, 32, (struct Color){ 255, 255, 255, 255 });
		RenderEnd();
	}

	RendererCleanup();
	WindowCleanup();
	ArenaCleanup();

	return 0;
}

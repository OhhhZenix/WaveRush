#include "core/allocator.h"
#include "core/input.h"
#include "core/renderer.h"
#include "core/window.h"
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaInit(memInMegabytes);

	WindowInit("Hello World", 640, 360);
	RendererInit();

	int32_t x = 0;
	int32_t y = 0;
	while (!WindowShouldClose()) {
		WindowPollEvents();
		if (IsKeyDown(4)) {
			x -= 1;
		}
		if (IsKeyDown(7)) {
			x += 1;
		}
		if (IsKeyDown(26)) {
			y -= 1;
		}
		if (IsKeyDown(22)) {
			y += 1;
		}

		RenderBegin((struct Color){ 0, .a = 255 });
		DrawRectangle(x, y, 32, 32, (struct Color){ 255, 255, 255, 255 });
		RenderEnd();
	}

	RendererCleanup();
	WindowCleanup();
	ArenaCleanup();

	return 0;
}

#include "core/allocator.h"
#include <nebula/nebula.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t memInMegabytes = 1 * 1024 * 1024;
	ArenaInit(memInMegabytes);

	nebula_init();
	nebula_window_init("Hello World", 640, 360);
	nebula_renderer_init();

	int32_t x = 0;
	int32_t y = 0;
	while (!nebula_window_should_close()) {
		nebula_window_poll_events();
		// if (IsKeyDown(NEBULA_KEYCODE_A)) {
		// 	x -= 1;
		// }
		// if (IsKeyDown(NEBULA_KEYCODE_D)) {
		// 	x += 1;
		// }
		// if (IsKeyDown(NEBULA_KEYCODE_W)) {
		// 	y -= 1;
		// }
		// if (IsKeyDown(NEBULA_KEYCODE_S)) {
		// 	y += 1;
		// }

		nebula_render_begin((struct Color){ 0, .a = 255 });
		nebula_draw_rect(x, y, 32, 32, (struct Color){ 255, 255, 255, 255 });
		nebula_render_end();
	}

	nebula_renderer_cleanup();
	nebula_window_cleanup();
	nebula_cleanup();
	ArenaCleanup();

	return 0;
}

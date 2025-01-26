#include "core/allocator.h"
#include <nebula/nebula.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
	uint32_t mem_in_megabytes = 1 * 1024 * 1024;
	arena_init(mem_in_megabytes);

	nebula_init("Wave Rush", 640, 360);

	float x = 0;
	float y = 0;
	uint32_t texture_id = nebula_load_texture("assets/textures/test.png");
	while (!nebula_window_should_close()) {
		nebula_window_poll_events();

		double dt = nebula_get_frame_time_in_seconds();
		if (nebula_is_key_down(NEBULA_KEY_A)) {
			x -= 100 * dt;
		}
		if (nebula_is_key_down(NEBULA_KEY_D)) {
			x += 100 * dt;
		}
		if (nebula_is_key_down(NEBULA_KEY_W)) {
			y -= 100 * dt;
		}
		if (nebula_is_key_down(NEBULA_KEY_S)) {
			y += 100 * dt;
		}

		nebula_render_begin((struct NebulaColor){ .a = 255 });
		nebula_draw_texture(texture_id, x, y, 32, 32, (struct NebulaColor){ 255, 255, 255, 255 });
		nebula_render_end();
	}

	nebula_cleanup();
	arena_cleanup();

	return 0;
}

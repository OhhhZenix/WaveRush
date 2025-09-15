#define SDL_MAIN_USE_CALLBACKS 1

#include "WaveRush/Core/Global.hpp"
#include "WaveRush/Scene/PlayScene.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <print>

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		std::println("Failed to initialize SDL: {}", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	global.window = SDL_CreateWindow("Wave Rush", 640, 360, SDL_WINDOW_OPENGL);
	if (!global.window) {
		std::println("Failed to create window: {}", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	global.renderer = SDL_CreateRenderer(global.window, nullptr);
	if (!global.renderer) {
		std::println("Failed to create renderer: {}", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	play_scene_init(&global.play_scene);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
	switch (event->type) {
		case SDL_EVENT_QUIT:
			return SDL_APP_SUCCESS;
		case SDL_EVENT_KEY_DOWN:
			global.is_keydown[event->key.key] = true;
			return SDL_APP_CONTINUE;
		case SDL_EVENT_KEY_UP:
			global.is_keydown[event->key.key] = false;
			return SDL_APP_CONTINUE;
		default:
			return SDL_APP_CONTINUE;
	}
}

SDL_AppResult SDL_AppIterate(void* appstate) {
	// update
	play_scene_update(&global.play_scene);

	// render
	SDL_SetRenderDrawColor(global.renderer, 64, 64, 64, 255);
	SDL_RenderClear(global.renderer);
	play_scene_render(&global.play_scene);
	SDL_RenderPresent(global.renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
	SDL_DestroyRenderer(global.renderer);
	SDL_DestroyWindow(global.window);
	SDL_Quit();
}

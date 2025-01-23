#include "core/window.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_video.h"
#include "core/engine.h"

#include <SDL3/SDL.h>
#include <stdlib.h>

void WindowInit(const char* title, uint32_t width, uint32_t height) {
	SDL_Init(SDL_INIT_VIDEO);

	context.window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (context.window == NULL) {
		exit(EXIT_FAILURE);
	}

	context.should_close = false;
}

void WindowCleanup() {
	SDL_DestroyWindow(context.window);
	SDL_Quit();
}

void WindowPollEvents() {
	SDL_Event event = {};
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_EVENT_QUIT) {
			context.should_close = true;
		}
	}
}

bool WindowShouldClose() {
	return context.should_close;
}

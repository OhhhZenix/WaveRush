#include "core/renderer.h"
#include "SDL3/SDL_render.h"

#include <SDL3/SDL.h>
#include <stdlib.h>

struct Renderer {
	SDL_Renderer* ptr;
};

static struct Renderer context = {};

void RendererInit(void* window) {
	SDL_Window* sdl_window = (SDL_Window*)window;

	context.ptr = SDL_CreateRenderer(sdl_window, NULL);

	if (context.ptr == NULL) {
		exit(EXIT_FAILURE);
	}
}

void RendererCleanup() {
	SDL_DestroyRenderer(context.ptr);
}

void RenderBegin() {
	SDL_SetRenderDrawColor(context.ptr, 0, 0, 0, 255);
	SDL_RenderClear(context.ptr);
}

void RenderEnd() {
	SDL_RenderPresent(context.ptr);
}

void DrawRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height) {
	SDL_FRect rect = {
		.x = x,
		.y = y,
		.w = width,
		.h = height,
	};
	SDL_SetRenderDrawColor(context.ptr, 255, 255, 255, 255);
	SDL_RenderFillRect(context.ptr, &rect);
}

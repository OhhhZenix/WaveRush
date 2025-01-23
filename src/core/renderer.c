#include "core/renderer.h"

#include "core/engine.h"
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void RendererInit() {
	context.renderer = SDL_CreateRenderer(context.window, NULL);

	if (context.renderer == NULL) {
		exit(EXIT_FAILURE);
	}
}

void RendererCleanup() {
	SDL_DestroyRenderer(context.renderer);
}

void RenderBegin(struct Color color) {
	SDL_SetRenderDrawColor(context.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(context.renderer);
}

void RenderEnd() {
	SDL_RenderPresent(context.renderer);
}

void DrawRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height, struct Color color) {
	SDL_FRect rect = {
		.x = x,
		.y = y,
		.w = width,
		.h = height,
	};
	SDL_SetRenderDrawColor(context.renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(context.renderer, &rect);
}

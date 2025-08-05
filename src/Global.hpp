#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct Global {
	SDL_Window* window;
	SDL_Renderer* renderer;
};

extern Global global;
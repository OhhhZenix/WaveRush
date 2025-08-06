#pragma once

#include "Entity/Player.hpp"
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <unordered_map>

struct Global {
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::unordered_map<SDL_Keycode, bool> is_keydown;
	Player player;
};

extern Global global;
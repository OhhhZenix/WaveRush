#pragma once

#include "WaveRush/Core/ArenaAllocator.hpp"
#include <SDL3/SDL.h>

struct Game {
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	u64 lastTime;
	u64 currentTime;
	f64 deltaTime;
};

Game* GameNew(ArenaAllocator* allocator);
void GameDelete(Game* game);
void GameRun(Game* game);
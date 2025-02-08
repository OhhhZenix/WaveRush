#pragma once

#include "Entity/Player.hpp"
#include <SDL3/SDL.h>

struct Game {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = true;
	Player* player = nullptr;

	Game();
	~Game();
	void run();
};

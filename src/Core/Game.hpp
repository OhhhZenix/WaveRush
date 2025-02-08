#pragma once

#include <SDL3/SDL.h>

struct Player;

struct Game {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = true;
	Player* player = nullptr;

	Game();
	~Game();
	void run();
};

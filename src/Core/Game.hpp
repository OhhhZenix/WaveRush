#pragma once

#include <SDL3/SDL.h>
#include <cstdint>
#include <unordered_map>

struct Player;

struct Game {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = true;
	std::unordered_map<uint32_t, bool> isKeyDown = {};
	Player* player = nullptr;

	Game();
	~Game();
	void run();
};

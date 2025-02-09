#pragma once

#include "Core/Types.hpp"
#include <SDL3/SDL.h>
#include <unordered_map>

struct Player;

struct Game {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool isRunning = true;
	std::unordered_map<u32, bool> isKeyDown = {};
	u64 lastTime = 0;
	u64 currentTime = 0;
	f64 deltaTime = 0;
	Player* player = nullptr;

	Game();
	~Game();
	void run();
};

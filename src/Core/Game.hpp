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
	Player* player = nullptr;

	Game();
	~Game();
	f64 getDeltaTime();
	f64 getDeltaTimeInSeconds();
	void run();
};

// #include "Game.hpp"

// #include "Entity/Player.hpp"
// #include "SDL3/SDL_render.h"
// #include <SDL3_image/SDL_image.h>

// Game::Game() {
// 	SDL_Init(SDL_INIT_VIDEO);
// 	this->window = SDL_CreateWindow("Wave Rush", 640, 360, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
// 	this->renderer = SDL_CreateRenderer(this->window, nullptr);

// 	this->textures[TEXTURE_PLAYER] = IMG_LoadTexture(this->renderer, "assets/textures/test.png");

// 	this->player = new Player({ 0, 0 });
// }

// Game::~Game() {
// 	delete this->player;

// 	for (auto texture : this->textures) {
// 		SDL_DestroyTexture(texture.second);
// 	}

// 	SDL_DestroyRenderer(this->renderer);
// 	SDL_DestroyWindow(this->window);
// 	SDL_Quit();
// }

// void Game::Run() {
// 	SDL_Event event = { 0 };
// 	while (isRunning) {
// 		while (SDL_PollEvent(&event)) {
// 			switch (event.type) {
// 				case SDL_EVENT_QUIT:
// 					this->isRunning = false;
// 					break;
// 				case SDL_EVENT_KEY_DOWN:
// 					this->isKeyDown[event.key.key] = true;
// 					break;
// 				case SDL_EVENT_KEY_UP:
// 					this->isKeyDown[event.key.key] = false;
// 					break;
// 				default:
// 					break;
// 			}
// 		}

// 		this->player->Update(this);

// 		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
// 		SDL_RenderClear(this->renderer);
// 		this->player->Render(this);
// 		SDL_RenderPresent(this->renderer);

// 		this->lastTime = this->currentTime;
// 		this->currentTime = SDL_GetPerformanceCounter();
// 		this->deltaTime = (this->currentTime - this->lastTime) / (f64)SDL_GetPerformanceFrequency();
// 	}
// }

#include "WaveRush/Core/Game.hpp"

Game* GameNew(ArenaAllocator* allocator) {
	Game* game = (Game*)ArenaAllocatorAllocate(allocator, sizeof(Game));

	if (!game) {
		SDL_Log("Failed to allocate memory for Game instance");
		return nullptr;
	}

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return nullptr;
	}

	game->window = SDL_CreateWindow("Wave Rush", 640, 360, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (!game->window) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return nullptr;
	}

	game->renderer = SDL_CreateRenderer(game->window, nullptr);
	if (!game->renderer) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		SDL_DestroyWindow(game->window);
		return nullptr;
	}

	game->isRunning = true;
	game->lastTime = 0;
	game->currentTime = 0;
	game->deltaTime = 0;

	return game;
}

void GameDelete(Game* game) {
	if (!game) {
		return;
	}

	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}

void GameRun(Game* game) {
	SDL_Event event = { 0 };
	while (game->isRunning) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					game->isRunning = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					// game->isKeyDown[event.key.key] = true;
					break;
				case SDL_EVENT_KEY_UP:
					// game->isKeyDown[event.key.key] = false;
					break;
				default:
					break;
			}
		}

		// Update and render logic would go here

		SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
		SDL_RenderClear(game->renderer);
		// Render entities here
		SDL_RenderPresent(game->renderer);

		game->lastTime = game->currentTime;
		game->currentTime = SDL_GetPerformanceCounter();
		game->deltaTime = (game->currentTime - game->lastTime) / (f64)SDL_GetPerformanceFrequency();
	}
}
#include "Game.hpp"

#include "Entity/Player.hpp"
#include "SDL3/SDL_events.h"

Game::Game() {
	SDL_Init(SDL_INIT_VIDEO);
	this->window = SDL_CreateWindow("Wave Rush", 640, 320, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	this->renderer = SDL_CreateRenderer(this->window, nullptr);
	this->player = new Player({ 0, 0 });
}

Game::~Game() {
	delete this->player;
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Game::run() {
	SDL_Event event = { 0 };
	while (isRunning) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					this->isRunning = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					this->isKeyDown[event.key.key] = true;
					break;
				case SDL_EVENT_KEY_UP:
					this->isKeyDown[event.key.key] = false;
					break;
				default:
					break;
			}
		}

		this->player->update(this);

		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
		SDL_RenderClear(this->renderer);
		this->player->render(this);
		SDL_RenderPresent(this->renderer);
	}
}
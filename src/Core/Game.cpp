#include "Game.hpp"

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
				default:
					break;
			}
		}

		this->player->update();

		SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
		SDL_RenderClear(this->renderer);
		this->player->render();
		SDL_RenderPresent(this->renderer);
	}
}
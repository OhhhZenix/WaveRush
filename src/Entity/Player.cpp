#include "Player.hpp"

#include "Core/Game.hpp"
#include "Core/Types.hpp"

#include <SDL3/SDL.h>

Player::Player(glm::vec2 startingPosition) {
	this->position = startingPosition;
}

void Player::Update(Game* game) {
	glm::vec2 direction = { 0, 0 };
	f32 distance = 1000;
	f32 time = game->deltaTime;

	if (game->isKeyDown[SDLK_UP]) {
		direction.y -= 1;
	}

	if (game->isKeyDown[SDLK_LEFT]) {
		direction.x -= 1;
	}

	if (game->isKeyDown[SDLK_DOWN]) {
		direction.y += 1;
	}

	if (game->isKeyDown[SDLK_RIGHT]) {
		direction.x += 1;
	}

	if (glm::length(direction) > 0) {
		this->position += glm::normalize(direction) * distance * time;
	}
}

void Player::Render(Game* game) {
	SDL_FRect rect = { this->position.x, this->position.y, this->size.x, this->size.y };
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
	SDL_RenderTexture(game->renderer, game->textures[TEXTURE_PLAYER], nullptr, &rect);
}

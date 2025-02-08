#include "Player.hpp"

#include "Core/Game.hpp"
#include "Core/Types.hpp"

Player::Player(glm::vec2 startingPosition) {
	this->position = startingPosition;
}

Player::~Player() {}

void Player::update(Game* game) {
	glm::vec2 direction = { 0, 0 };
	f32 speed = 1;
	f32 dt = game->getDeltaTimeInSeconds();

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
		this->position += glm::normalize(direction * speed * dt);
	}
}

void Player::render(Game* game) {
	SDL_FRect rect = { this->position.x, this->position.y, this->size.x, this->size.y };
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(game->renderer, &rect);
}
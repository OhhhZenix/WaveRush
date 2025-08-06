#include "Entity/Player.hpp"

#include "Core/Global.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_scancode.h>

constexpr float PLAYER_SPEED = 1.0f;
constexpr float PLAYER_SIZE = 32.0f;

Player::Player(const glm::vec2& position) {
	this->position = position;
}

glm::vec2 Player::getPosition() const {
	return this->position;
}

void Player::processUpdate() {
	glm::vec2 velocity = { 0, 0 };

	if (global.is_keydown[SDLK_W]) {
		velocity.y = -1;
	}

	if (global.is_keydown[SDLK_A]) {
		velocity.x = -1;
	}

	if (global.is_keydown[SDLK_S]) {
		velocity.y = 1;
	}

	if (global.is_keydown[SDLK_D]) {
		velocity.x = 1;
	}

	this->position += velocity * PLAYER_SPEED;
}

void Player::processRender() {
	SDL_FRect rect = { this->position.x, this->position.y, PLAYER_SIZE, PLAYER_SIZE };
	SDL_SetRenderDrawColor(global.renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(global.renderer, &rect);
}
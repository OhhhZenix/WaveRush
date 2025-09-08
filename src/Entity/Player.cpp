#include "Entity/Player.hpp"

#include "Core/Global.hpp"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_scancode.h>

constexpr float PLAYER_SPEED = 1.0f;
constexpr float PLAYER_SIZE = 32.0f;

void player_init(Player* self) {
	if (!self) {
		return;
	}

	self->position.x = 0;
	self->position.y = 0;
}

void player_update(Player* self) {
	if (!self) {
		return;
	}

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

	self->position += velocity * PLAYER_SPEED;
}

void player_render(Player* self) {
	if (!self) {
		return;
	}

	SDL_FRect rect = { self->position.x, self->position.y, PLAYER_SIZE, PLAYER_SIZE };
	SDL_SetRenderDrawColor(global.renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(global.renderer, &rect);
}
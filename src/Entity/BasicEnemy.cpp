#include "Entity/BasicEnemy.hpp"

#include "Core/Constants.hpp"
#include "Core/Global.hpp"
#include <SDL3/SDL_rect.h>
#include <cstdlib>

void basic_enemy_init(BasicEnemy* self) {
	if (!self) {
		return;
	}

	self->position.x = rand() % SCREEN_WIDTH;
	self->position.y = rand() % SCREEN_HEIGHT;

	self->velocity.x = (rand() % 2) ? 1 : -1;
	self->velocity.y = (rand() % 2) ? 1 : -1;
}

void basic_enemy_update(BasicEnemy* self) {
	if (!self) {
		return;
	}

	// Move enemy
	self->position.x += self->velocity.x * BASIC_ENEMY_SPEED;
	self->position.y += self->velocity.y * BASIC_ENEMY_SPEED;

	// Check horizontal boundaries
	if (self->position.x < 0) {
		self->position.x = 0;
		self->velocity.x *= -1;
	} else if (self->position.x >= SCREEN_WIDTH) {
		self->position.x = SCREEN_WIDTH - 1;
		self->velocity.x *= -1;
	}

	// Check vertical boundaries
	if (self->position.y < 0) {
		self->position.y = 0;
		self->velocity.y *= -1;
	} else if (self->position.y >= SCREEN_HEIGHT) {
		self->position.y = SCREEN_HEIGHT - 1;
		self->velocity.y *= -1;
	}
}

void basic_enemy_render(BasicEnemy* self) {
	if (!self) {
		return;
	}

	SDL_FRect rect = { self->position.x, self->position.y, BASIC_ENEMY_SIZE, BASIC_ENEMY_SIZE };
	SDL_SetRenderDrawColor(global.renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(global.renderer, &rect);
}
#pragma once

#include <SDL3/SDL.h>
#include <glm/vec2.hpp>

struct Game;

struct Player {
	glm::vec2 position = { 0, 0 };
	glm::vec2 size = { 32, 32 };

	Player(glm::vec2 startingPosition);
	~Player();
	void update(Game* game);
	void render(Game* game);
};
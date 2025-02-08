#pragma once

#include <SDL3/SDL.h>
#include <glm/vec2.hpp>

struct Game;

struct Player {
	glm::vec2 position;
	glm::vec2 size;

	Player(glm::vec2 startingPosition);
	~Player();
	void update(Game* game);
	void render(Game* game);
};
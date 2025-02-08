#pragma once

#include <glm/vec2.hpp>

struct Player {
	glm::vec2 position;
	glm::vec2 size;

	Player(glm::vec2 startingPosition);
	~Player();
	void update();
	void render();
};
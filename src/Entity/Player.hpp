#pragma once

#include <glm/glm.hpp>

struct Game;

struct Player {
	glm::vec2 position = { 0, 0 };
	glm::vec2 size = { 32, 32 };

	Player(glm::vec2 startingPosition = { 0, 0 });
	void Update(Game* game);
	void Render(Game* game);
};

#pragma once

#include <glm/vec2.hpp>

struct Player {
	glm::vec2 position;
};

void player_init(Player* self);
void player_update(Player* self);
void player_render(Player* self);
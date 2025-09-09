#pragma once

#include <glm/vec2.hpp>

struct BasicEnemy {
	glm::vec2 position;
	glm::vec2 velocity;
};

void basic_enemy_init(BasicEnemy* self);
void basic_enemy_update(BasicEnemy* self);
void basic_enemy_render(BasicEnemy* self);
#pragma once

#include <cstddef>
#include <cstdint>
#include <glm/glm.hpp>

#include "WaveRush/Core/Arena.h"

enum class wr_entity_type : uint32_t {
  Entity = 0,
  Player,
  BasicEnemy,
  SmartEnemy,
  Particle,
};

struct wr_entity {
  wr_entity_type type;
  glm::vec2 position;
  bool dead;
};

struct wr_world {
  wr_entity* entities;
  size_t next_slot;
};

void wr_world_init(wr_world* world, wr_arena* arena, size_t max_entities);
wr_entity* wr_world_add_entity(wr_world* world);
void wr_world_remove_entity(wr_world* world, wr_entity* entity);
#pragma once

#include <cstddef>
#include <cstdint>
#include <glm/glm.hpp>

#include "WaveRush/Core/Arena.h"
#include "WaveRush/Core/Queue.h"

struct wr_entity {
  glm::vec3 position;
  glm::vec3 rotation;
  glm::vec3 scale;
};

struct wr_entity_ref {
  size_t index;
  uint32_t generation;
};

struct wr_world {
  wr_queue<size_t> free_slots;
  wr_entity* entities;    // actual entity
  uint32_t* generations;  // used for stale
  bool* used;             // used for alive
  size_t length;          // how many entities
};

void wr_world_init(wr_world* world, wr_arena* arena, size_t max_entities);
wr_entity* wr_world_get(wr_world* world, wr_entity_ref ref);
wr_entity_ref wr_world_add(wr_world* world);
void wr_world_rem(wr_world* world, wr_entity_ref ref);

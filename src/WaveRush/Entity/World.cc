#include "World.h"

#include <cassert>
#include <cstring>

#include "WaveRush/Core/Queue.h"

void wr_world_init(wr_world* world, wr_arena* arena, size_t max_entities) {
  world->entities =
      (wr_entity*)wr_arena_alloc(arena, sizeof(wr_entity) * max_entities);

  world->generations =
      (uint32_t*)wr_arena_alloc(arena, sizeof(uint32_t) * max_entities);

  world->alive = (bool*)wr_arena_alloc(arena, sizeof(bool) * max_entities);

  world->capacity = max_entities;

  wr_queue_init(&world->free_slots, max_entities, sizeof(size_t), arena);
  for (size_t i = 0; i < max_entities; i++) {
    wr_queue_push(&world->free_slots, &i);
  }
}

wr_entity* wr_world_get(wr_world* world, wr_entity_ref ref) {
  if (ref.index < 0) {
    return nullptr;
  }

  if (ref.index > world->capacity) {
    return nullptr;
  }

  if (ref.generation != world->generations[ref.index]) {
    return nullptr;
  }

  if (world->alive[ref.index] == false) {
    return nullptr;
  }

  return &world->entities[ref.index];
}

wr_entity_ref wr_world_add(wr_world* world) {
  size_t index = 0;
  wr_queue_pop(&world->free_slots, &index);
  world->alive[index] = true;
  return {
      .index = index,
      .generation = world->generations[index],
  };
}

void wr_world_rem(wr_world* world, wr_entity_ref ref) {
  wr_entity* entity = wr_world_get(world, ref);

  if (entity == nullptr) {
    return;
  }

  wr_queue_push(&world->free_slots, &ref.index);
  world->generations[ref.index] += 1;
  world->alive[ref.index] = false;
}

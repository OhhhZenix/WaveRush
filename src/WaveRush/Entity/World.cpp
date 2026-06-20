#include "World.h"

#include <cstring>

void wr_world_init(wr_world* world, wr_arena* arena, size_t max_entities) {
  world->entities =
      (wr_entity*)wr_arena_alloc(arena, sizeof(wr_entity) * max_entities);
  world->generations =
      (size_t*)wr_arena_alloc(arena, sizeof(size_t) * max_entities);
  world->max_slots = max_entities;
  world->next_slot = 0;
}

wr_entity_handle wr_world_add_entity(wr_world* world) {
  wr_entity* entity = &world->entities[world->next_slot++];
  memset(entity, 0, sizeof(wr_entity));
  return {};
}

void wr_world_remove_entity(wr_world* world, wr_entity_handle entity) {}
#include "WaveRush/Entity.h"

#include <cassert>

#include "WaveRush/Arena.h"
#include "WaveRush/Vec2f.h"

#define MAX_ENTITIES 1'000

void wr_entity_manager_init(EntityManager* entities, Arena* arena) {
    entities->position =
        (Vec2f*)wr_arena_push(arena, sizeof(Vec2f) * MAX_ENTITIES);
    entities->velocity =
        (Vec2f*)wr_arena_push(arena, sizeof(Vec2f) * MAX_ENTITIES);
    entities->size = (Vec2f*)wr_arena_push(arena, sizeof(Vec2f) * MAX_ENTITIES);
    entities->kind =
        (EntityKind*)wr_arena_push(arena, sizeof(EntityKind) * MAX_ENTITIES);
    entities->alive = (bool*)wr_arena_push(arena, sizeof(bool) * MAX_ENTITIES);
    entities->count = 0;

    for (size_t i = 0; i < MAX_ENTITIES; i++) {
        entities->position[i] = {0, 0};
        entities->velocity[i] = {0, 0};
        entities->size[i] = {0, 0};
        entities->kind[i] = EntityKind_None;
        entities->alive[i] = false;
    }
}

size_t wr_create_entity(EntityManager* entity_manager) {
    assert(entity_manager->count < MAX_ENTITIES && "Reached max entity count");
    return entity_manager->count++;
}

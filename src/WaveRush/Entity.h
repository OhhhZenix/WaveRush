#pragma once

#include <cstddef>

struct Vec2f;
struct Arena;

enum EntityKind {
    EntityKind_None,
    EntityKind_Player,
    EntityKind_Bouncer,
};

struct EntityManager {
    EntityKind* kind;
    Vec2f* position;
    Vec2f* velocity;
    Vec2f* size;
    bool* alive;
    size_t count;
};

void wr_entity_manager_init(EntityManager* entities, Arena* arena);

size_t wr_create_entity(EntityManager* entity_manager);

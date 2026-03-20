#include "WaveRush/Bouncer.h"

#include <cstddef>
#include <cstdlib>

#include "WaveRush/Entity.h"
#include "WaveRush/Game.h"
#include "WaveRush/Vec2f.h"

void wr_spawn_bouncer(EntityManager* entity_manager) {
    size_t bouncer = wr_create_entity(entity_manager);
    entity_manager->alive[bouncer] = true;
    entity_manager->kind[bouncer] = EntityKind_Bouncer;
    entity_manager->position[bouncer].x = rand() % (GAME_WIDTH - 16);
    entity_manager->position[bouncer].y = rand() % (GAME_HEIGHT - 16);
    entity_manager->velocity[bouncer].x = (rand() % 2) * 2 - 1;
    entity_manager->velocity[bouncer].y = (rand() % 2) * 2 - 1;
    entity_manager->size[bouncer] = {16, 16};
}

void wr_bouncer_movement_system(EntityManager* entity_manager) {
    for (size_t i = 0; i < entity_manager->count; i++) {
        if (!entity_manager->alive[i]) {
            continue;
        }

        if (entity_manager->kind[i] != EntityKind_Bouncer) {
            continue;
        }

        Vec2f* pos = &entity_manager->position[i];
        Vec2f* vel = &entity_manager->velocity[i];
        Vec2f* size = &entity_manager->size[i];

        if (pos->x < 0 || pos->x > GAME_WIDTH - size->x) {
            vel->x *= -1;
        }

        if (pos->y < 0 || pos->y > GAME_HEIGHT - size->y) {
            vel->y *= -1;
        }
    }
}

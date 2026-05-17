#include "WaveRush/Player.h"

#include <cstdlib>

#include "WaveRush/Entity.h"
#include "WaveRush/Game.h"
#include "WaveRush/Vec2f.h"
#include "raylib.h"

#define PLAYER_SPEED 2

void wr_spawn_player(EntityManager* entity_manager) {
    size_t player = wr_create_entity(entity_manager);
    entity_manager->alive[player] = true;
    entity_manager->kind[player] = EntityKind_Player;
    entity_manager->position[player] = {
        (float)(rand() % (GAME_WIDTH - 32)),
        (float)(rand() % (GAME_HEIGHT - 32))
    };
    entity_manager->velocity[player] = {0, 0};
    entity_manager->size[player] = {32, 32};
}

void wr_player_movement_system(EntityManager* entity_manager) {
    for (size_t i = 0; i < entity_manager->count; i++) {
        if (!entity_manager->alive[i]) {
            continue;
        }

        if (entity_manager->kind[i] != EntityKind_Player) {
            continue;
        }

        if (IsKeyDown(KEY_W)) {
            entity_manager->velocity[i].y = -PLAYER_SPEED;
        } else if (IsKeyDown(KEY_S)) {
            entity_manager->velocity[i].y = PLAYER_SPEED;
        } else {
            entity_manager->velocity[i].y = 0;
        }

        if (IsKeyDown(KEY_A)) {
            entity_manager->velocity[i].x = -PLAYER_SPEED;
        } else if (IsKeyDown(KEY_D)) {
            entity_manager->velocity[i].x = PLAYER_SPEED;
        } else {
            entity_manager->velocity[i].x = 0;
        }
    }
}

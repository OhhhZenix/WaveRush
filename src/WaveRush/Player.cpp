#include "WaveRush/Player.h"

#include <cstdlib>

#include "WaveRush/Entity.h"
#include "WaveRush/Game.h"
#include "WaveRush/Vec2f.h"

void wr_spawn_player(EntityManager* entity_manager) {
    size_t player = wr_create_entity(entity_manager);
    entity_manager->alive[player] = true;
    entity_manager->kind[player] = EntityKind_Player;
    entity_manager->position[player].x = rand() % (GAME_WIDTH - 32);
    entity_manager->position[player].y = rand() % (GAME_HEIGHT - 32);
    entity_manager->velocity[player] = {0, 0};
    entity_manager->size[player] = {32, 32};
}

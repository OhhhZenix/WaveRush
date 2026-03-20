#include "WaveRush/Game.h"

#include <raylib.h>

#include <cstddef>
#include <cstdlib>
#include <ctime>

#include "WaveRush/Arena.h"
#include "WaveRush/Entity.h"
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

void wr_game_init(Game* game, Arena* main_allocator) {
    wr_entity_manager_init(game->entity_manager, main_allocator);
    wr_spawn_bouncer(game->entity_manager);
    wr_spawn_bouncer(game->entity_manager);
    wr_spawn_bouncer(game->entity_manager);
    wr_spawn_bouncer(game->entity_manager);
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

void wr_physics_system(EntityManager* entity_manager, float dt) {
    for (size_t i = 0; i < entity_manager->count; i++) {
        if (!entity_manager->alive[i]) {
            continue;
        }

        vec2f_add(&entity_manager->position[i], &entity_manager->velocity[i]);
        // entity_manager->position[i].x += entity_manager->velocity[i].x;
        // entity_manager->position[i].y += entity_manager->velocity[i].y;
    }
}

void wr_simple_render_system(EntityManager* entity_manager) {
    for (size_t i = 0; i < entity_manager->count; i++) {
        if (!entity_manager->alive[i]) {
            continue;
        }

        DrawRectangle(
            entity_manager->position[i].x,
            entity_manager->position[i].y,
            entity_manager->size[i].x,
            entity_manager->size[i].y,
            WHITE
        );
    }
}

void wr_game_tick(Game* game, Arena* frame_allocator) {
    wr_arena_push(frame_allocator, 128);

    // update
    float dt = GetFrameTime();
    wr_physics_system(game->entity_manager, dt);
    wr_bouncer_movement_system(game->entity_manager);

    // render
    wr_simple_render_system(game->entity_manager);
}

void wr_game_run(void) {
    srand(time(NULL));

    Arena main_allocator;
    wr_arena_init(&main_allocator, 1024 * 1024 * 1024);

    Game game;
    wr_game_init(&game, &main_allocator);

    Arena frame_allocator;
    wr_arena_init(&frame_allocator, 1024);

    SetTargetFPS(60);
    InitWindow(640, 360, "WaveRush");

    while (!WindowShouldClose()) {
        wr_arena_reset(&frame_allocator);
        BeginDrawing();
        ClearBackground(BLACK);
        wr_game_tick(&game, &frame_allocator);
        EndDrawing();
    }

    CloseWindow();
    wr_arena_deinit(&frame_allocator);
    wr_arena_deinit(&main_allocator);
}
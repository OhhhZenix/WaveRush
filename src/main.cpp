#include <raylib.h>

#include "wr/constants.h"
#include "wr/scene.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);

    wr_scene current_scene = WR_SCENE_PLAY;
    wr_play_scene scene;
    wr_play_scene_init(&scene);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (current_scene) {
            case WR_SCENE_PLAY:
                wr_play_scene_update(&scene, &current_scene);
                wr_play_scene_draw(&scene);
                break;
            default:
                break;
        }

        EndDrawing();
    }

    return 0;
}
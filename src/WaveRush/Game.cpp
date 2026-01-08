#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

auto Game::GetSceneManager() -> SceneManager& {
    return this->scene_manager;
}

auto Game::Close() -> void {
    this->should_close = true;
}

auto Game::Run() -> void {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);

    this->GetSceneManager().GotoNextScene(new MainMenuScene());

    while (!WindowShouldClose()) {
        if (this->should_close)
            break;

        // update loop
        this->GetSceneManager().Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        this->GetSceneManager().Render();
        EndDrawing();
    }

    CloseWindow();
}

} // namespace WaveRush

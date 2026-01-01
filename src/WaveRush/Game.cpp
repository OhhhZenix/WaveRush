#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

Game::Game() {}

Game::~Game() {}

SceneManager& Game::GetSceneManager() {
    return this->scene_manager;
}

void Game::Close() {
    this->should_close = true;
}

void Game::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);

    this->GetSceneManager().GotoNextScene(new MainMenuScene());

    while (!WindowShouldClose()) {
        if (this->should_close)
            break;

        // update loop
        this->GetSceneManager().GetCurrentScene().Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        this->GetSceneManager().GetCurrentScene().Render();
        EndDrawing();
    }

    CloseWindow();
}

} // namespace WaveRush

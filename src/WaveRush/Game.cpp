#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Scene/MainMenuScene.hpp"
#include "WaveRush/Constants.hpp"

namespace WaveRush {

Game::Game() {
    this->scene.push(std::make_unique<MainMenuScene>());
}

Game::~Game() {}

void Game::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
        this->scene.top()->Update();

        BeginDrawing();
        ClearBackground(WHITE);
        this->scene.top()->Render();
        EndDrawing();
    }
}

} // namespace WaveRush

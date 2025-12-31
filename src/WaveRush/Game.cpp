#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

Game::Game() {
    this->scene.push(std::make_unique<MainMenuScene>());
}

Game::~Game() {}

void Game::GotoPreviousScene() {
    if (this->scene.size() <= 1)
        return;
    this->scene.pop();
}

void Game::GotoNextScene(Scene* scene) {
    this->scene.emplace(scene);
}

void Game::Close() {
     this->should_close = true;
}


void Game::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
        if (this->should_close)
            break;

        // update loop
        this->scene.top()->Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        this->scene.top()->Render();
        EndDrawing();
    }

    CloseWindow();
}

} // namespace WaveRush

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

void Game::Run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
        this->scene.top()->Update(*this);

        BeginDrawing();
        ClearBackground(BLACK);
        this->scene.top()->Render();
        EndDrawing();
    }
}

} // namespace WaveRush

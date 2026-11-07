#include "WaveRush/Game.h"

#include "WaveRush/Constant.h"

#include <raylib.h>

namespace wr {

  Game::Game() : running_(true) {
    SetTargetFPS(wr::GAME_FPS);
    InitWindow(wr::GAME_WIDTH, wr::GAME_HEIGHT, "Wave Rush");
  }

  Game::~Game() {
    CloseWindow();
    running_ = false;
  }

  void Game::Run() {
    while (!WindowShouldClose() && IsRunning()) {

      BeginDrawing();
      ClearBackground(RAYWHITE);
      EndDrawing();
    }
  }

  auto Game::IsRunning() -> bool { return running_; }

  void Game::SetRunning(bool value) { running_ = value; }

} // namespace wr

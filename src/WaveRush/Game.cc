#include "WaveRush/Game.h"

#include "WaveRush/Constant.h"

#include <raylib.h>

namespace wr {

  Game::Game() {
    SetTargetFPS(wr::GAME_FPS);
    InitWindow(wr::GAME_WIDTH, wr::GAME_HEIGHT, "Wave Rush");
    running_ = true;
  }

  Game::~Game() {
    CloseWindow();
    running_ = false;
  }

  void Game::Run() {
    bool ok = !WindowShouldClose() && IsRunning();

    while (ok) {
      player_.Update();

      BeginDrawing();
      ClearBackground(RAYWHITE);
      player_.Render();
      EndDrawing();
    }
  }

  bool Game::IsRunning() const { return running_; }

  void Game::SetRunning(bool value) { running_ = value; }

} // namespace wr

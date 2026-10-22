#include "WaveRush/Game.h"

#include "WaveRush/Constant.h"

#include <raylib.h>

namespace wr {

  Game::Game() {
    InitWindow(wr::GAME_WIDTH, wr::GAME_HEIGHT, "Wave Rush");
    running_ = true;
  }

  Game::~Game() {
    CloseWindow();
    running_ = false;
  }

  void Game::Run() {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
      EndDrawing();
    }
  }

  bool Game::IsRunning() const { return running_; }

  void Game::SetRunning(bool value) { running_ = value; }

} // namespace wr
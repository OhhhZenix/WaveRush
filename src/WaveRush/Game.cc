#include "WaveRush/Game.h"

#include "WaveRush/Constant.h"
#include "WaveRush/Entity.h"

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
    wr::Player player{0, 0};
    while (!WindowShouldClose() && IsRunning()) {
      BeginDrawing();
      player.OnUpdate(*this);

      ClearBackground(RAYWHITE);
      player.OnRender(*this);
      EndDrawing();
    }
  }

  bool Game::IsRunning() const { return running_; }

  void Game::SetRunning(bool value) { running_ = value; }

} // namespace wr
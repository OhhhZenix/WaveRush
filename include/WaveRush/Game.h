#pragma once

#include "WaveRush/Entity/Player.h"

namespace wr {

  class Game {
  public:
    Game();
    ~Game();
    Game(const Game& game) = delete;                    // copy construct
    Game(Game&& game) = delete;                         // move construct
    auto operator=(const Game& game) -> Game& = delete; // copy assign
    auto operator=(Game&& game) -> Game& = delete;      // move assign
    void Run();
    auto IsRunning() -> bool;
    void SetRunning(bool value);

  private:
    bool running_;
    wr::Player player_;
  };

} // namespace wr

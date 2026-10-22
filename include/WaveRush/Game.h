#pragma once

namespace wr {

  class Game {
  public:
    Game();
    ~Game();
    Game(const Game& game) = delete;            // copy construct
    Game& operator=(const Game& game) = delete; // copy assign
    Game(Game&& game) = delete;                 // move construct
    Game& operator=(Game&& game) = delete;      // move assign
    void Run();

  private:
  };

} // namespace wr
#include "WaveRush/Core/Game.hpp"

auto main(int argc, char* argv[]) -> int {
  (void)argc;
  (void)argv;
  wr::Game game;
  game.run();
  return 0;
}

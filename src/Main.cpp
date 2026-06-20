#include "WaveRush/Core/Game.h"

int main() {
  wr_game game;

  if (wr_game_init(&game) == true) {
      wr_game_run(&game);
  }

  wr_game_cleanup(&game);

  return 0;
}

#include <glm/glm.hpp>
#include <raylib.h>

constexpr const int game_width = 1280;
constexpr const int game_height = 720;

int main() {
  InitWindow(game_width, game_height, "sdd");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    glm::ivec2 pos = {190, 200};
    DrawText("Congrats! You created your first window!", pos.x, pos.y, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
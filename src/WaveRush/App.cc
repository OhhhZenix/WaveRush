#include "App.h"

#include <raylib.h>

namespace wr {

App::App() {
  InitWindow(1280, 720, "WaveRush");
  running_ = true;
}

App::~App() {
  CloseWindow();
  running_ = false;
}

void App::run() {
  while (WindowShouldClose() == false && running_ == true) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // do stuff
    EndDrawing();
  }
}

}  // namespace wr
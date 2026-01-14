#include "WaveRush/Core/Window.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"

namespace WaveRush {

Window::Window() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wave Rush");
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);
}

Window::~Window() {
    CloseWindow();
}

auto Window::ShouldClose() const -> bool {
    return should_close_ || WindowShouldClose();
}

auto Window::Close() -> void {
    should_close_ = true;
}

} // namespace WaveRush

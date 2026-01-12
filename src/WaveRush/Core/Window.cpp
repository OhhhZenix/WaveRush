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
    return m_should_close || WindowShouldClose();
}

auto Window::Close() -> void {
    m_should_close = true;
}

} // namespace WaveRush

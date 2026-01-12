#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

auto Game::GetWindow() -> Window& {
    return m_window;
}

auto Game::GetSceneManager() -> SceneManager& {
    return m_scene_manager;
}

auto Game::Run() -> void {
    GetSceneManager().GotoNextScene(new MainMenuScene());

    while (!m_window.ShouldClose()) {
        // update loop
        GetSceneManager().Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        GetSceneManager().Render();
        EndDrawing();
    }
}

} // namespace WaveRush

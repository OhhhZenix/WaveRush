#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

auto Game::GetWindow() -> Window& {
    return m_window;
}

auto Game::GetSceneManager() -> SceneManager& {
    return this->scene_manager;
}

auto Game::Run() -> void {
    this->GetSceneManager().GotoNextScene(new MainMenuScene());

    while (!m_window.ShouldClose()) {
        // update loop
        this->GetSceneManager().Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        this->GetSceneManager().Render();
        EndDrawing();
    }
}

} // namespace WaveRush

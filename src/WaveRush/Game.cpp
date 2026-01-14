#include "WaveRush/Game.hpp"

#include <raylib.h>

#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

auto Game::GetWindow() -> Window& {
    return window_;
}

auto Game::GetSceneManager() -> SceneManager& {
    return scene_manager_;
}

auto Game::Run() -> void {
    GetSceneManager().GotoNextScene(new MainMenuScene());

    while (!window_.ShouldClose()) {
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

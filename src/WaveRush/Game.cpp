#include "WaveRush/Game.hpp"

#include <raylib.h>

#include <iostream>

#include "WaveRush/Entity/EntityManager.hpp"
#include "WaveRush/Entity/Player.hpp"
#include "WaveRush/Scene/MainMenuScene.hpp"

namespace WaveRush {

auto Game::GetWindow() -> Window& {
    return window_;
}

auto Game::GetSceneManager() -> SceneManager& {
    return scene_manager_;
}

auto Game::GetEntityManager() -> EntityManager& {
    return entity_manager_;
}

auto Game::Run() -> void {
    GetSceneManager().GotoNextScene(new MainMenuScene(*this));

    CreatePlayer(*this);

    while (!window_.ShouldClose()) {
        // update loop
        GetSceneManager().Update(*this);

        // draw loop
        BeginDrawing();
        ClearBackground(BLACK);
        float dt = GetFrameTime();
        std::cout << (1 / dt) << std::endl;
        GetSceneManager().Render();
        EndDrawing();
    }
}

} // namespace WaveRush

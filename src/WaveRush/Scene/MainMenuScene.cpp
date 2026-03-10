#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Game.hpp"

namespace WaveRush {

MainMenuScene::MainMenuScene(Game& game) {}

auto MainMenuScene::Update(Game& game) -> void {
    for (EntityHandle entity : game.GetEntityManager().GetActiveEntities()) {
        CPosition& pos = game.GetEntityManager().GetPosition(entity);
        if (pos.exists) {
            pos.x += 1;
        }
    }
    this->widget_manager_.Update(game);
}

auto MainMenuScene::Render() -> void {
    this->widget_manager_.Render();
}

} // namespace WaveRush

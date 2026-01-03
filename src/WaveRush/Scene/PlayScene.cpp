#include "WaveRush/Scene/PlayScene.hpp"

#include "WaveRush/Entity/Player.hpp"
#include "raylib.h"

namespace WaveRush {

PlayScene::PlayScene() {
    entity_manager.AddEntity(new Player());
}

void PlayScene::Update(Game& game) {
    if (!paused)
        entity_manager.Update(game);

    if (IsKeyDown(KEY_SPACE))
        this->paused = !paused;
}

void PlayScene::Render() {
    entity_manager.Render();
}

} // namespace WaveRush

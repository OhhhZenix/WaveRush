#include "WaveRush/Scene/PlayScene.hpp"

#include <raylib.h>

#include "WaveRush/Entity/Player.hpp"

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

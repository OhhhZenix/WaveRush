#include "WaveRush/Scene/PlayScene.hpp"

#include "WaveRush/Entity/Player.hpp"

namespace WaveRush {

PlayScene::PlayScene() {
    entity_manager.AddEntity(new Player());
}

void PlayScene::Update(Game& game) {
    entity_manager.Update(game);
}

void PlayScene::Render() {
    entity_manager.Render();
}

} // namespace WaveRush

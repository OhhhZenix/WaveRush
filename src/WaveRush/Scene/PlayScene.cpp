#include "WaveRush/Scene/PlayScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Widget.hpp"
#include "WaveRush/Widget/Button.hpp"
#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

PlayScene::PlayScene() {}

auto PlayScene::Update(Game& game) -> void {
    if (IsKeyPressed(KEY_ESCAPE))
        paused_ = !paused_;

    if (paused_)
        widget_manager_.Update(game);
}

auto PlayScene::Render() -> void {
    if (paused_)
        widget_manager_.Render();
}

} // namespace WaveRush

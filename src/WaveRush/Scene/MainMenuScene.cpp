#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Utils.hpp"
#include "WaveRush/Widget/Button.hpp"
#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

MainMenuScene::MainMenuScene() {}

auto MainMenuScene::Update(Game& game) -> void {
    this->widget_manager_.Update(game);
}

auto MainMenuScene::Render() -> void {
    this->widget_manager_.Render();
}

} // namespace WaveRush

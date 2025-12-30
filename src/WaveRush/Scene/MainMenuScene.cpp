#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Utils.hpp"

namespace WaveRush {

MainMenuScene::MainMenuScene() {
    for (int i = 0; i < 50; i++) {
        this->rects.push_back({
            (float)GenerateRandomIntRange(0, GAME_WIDTH),
            (float)GenerateRandomIntRange(0, GAME_HEIGHT),
            16,
            16,
        });
    }
}

void MainMenuScene::Update() {
    for (auto& rect : this->rects) {}
}

void MainMenuScene::Render() {
    for (auto& rect : this->rects) {
        DrawRectangle(rect.x, rect.y, rect.w, rect.h, BLUE);
    }
}

} // namespace WaveRush

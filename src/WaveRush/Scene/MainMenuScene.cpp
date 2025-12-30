#include "WaveRush/Scene/MainMenuScene.hpp"

#include "WaveRush/Constants.hpp"
#include "WaveRush/Utils.hpp"

namespace WaveRush {

MainMenuScene::MainMenuScene() {
    for (int i = 0; i < 50; i++) {
        auto color = Color {
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            255,
        };
        this->rects.push_back({
            GenerateRandomRange<float>(0, GAME_WIDTH),
            GenerateRandomRange<float>(0, GAME_HEIGHT),
            16,
            16,
            color,
        });
    }
}

void MainMenuScene::Update() {
    for (auto& rect : this->rects) {}
}

void MainMenuScene::Render() {
    for (auto& rect : this->rects) {
        DrawRectangle(rect.x, rect.y, rect.w, rect.h, rect.color);
    }
}

} // namespace WaveRush

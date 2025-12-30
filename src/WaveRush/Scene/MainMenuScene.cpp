#include "WaveRush/Scene/MainMenuScene.hpp"

#include "WaveRush/Constants.hpp"
#include "WaveRush/Utils.hpp"
#include "raylib.h"

namespace WaveRush {

MainMenuScene::MainMenuScene() {
    auto w = 16.f;
    auto h = 16.f;
    for (int i = 0; i < 50; i++) {
        auto color = Color {
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            GenerateRandomRange<unsigned char>(0, 255),
            255,
        };
        auto speed_x = GenerateRandomRange(.5f, 2.f);
        auto speed_y = GenerateRandomRange(.5f, 2.f);
        this->rects.push_back({
            GenerateRandomRange<float>(0 + w, GAME_WIDTH - w),
            GenerateRandomRange<float>(0 + h, GAME_HEIGHT - h),
            w,
            h,
            color,
            (GenerateRandomRange<int>(0, 1) ? -1.f : 1.f) * speed_x,
            (GenerateRandomRange<int>(0, 1) ? -1.f : 1.f) * speed_y,
        });
    }
}

void MainMenuScene::Update(Game& game) {
    for (auto& rect : this->rects) {
        if (rect.x <= 0 || rect.x >= GAME_WIDTH - rect.w)
            rect.vel_x *= -1.f;
        if (rect.y <= 0 || rect.y >= GAME_HEIGHT - rect.h)
            rect.vel_y *= -1.f;

        rect.x += rect.vel_x;
        rect.y += rect.vel_y;
    }

    if (IsKeyPressed(KEY_A)) {
        game.GotoPreviousScene();
    }

    if (IsKeyPressed(KEY_D)) {
        game.GotoNextScene(new MainMenuScene());
    }
}

void MainMenuScene::Render(const Game& game) {
    for (auto& rect : this->rects) {
        DrawRectangle(rect.x, rect.y, rect.w, rect.h, rect.color);
    }
}

} // namespace WaveRush

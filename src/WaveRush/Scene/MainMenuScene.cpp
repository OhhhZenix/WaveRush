#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Scene/PlayScene.hpp"
#include "WaveRush/Utils.hpp"
#include "WaveRush/Widget/Button.hpp"

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

    auto button_gap = 20;
    auto button_width = 180;
    auto button_height = 60;
    auto button_count = 2;
    auto play_button = new Button(
        (GAME_WIDTH - button_width) / 2,
        (GAME_HEIGHT - (button_height * button_count)) / 2,
        button_width,
        button_height,
        WHITE,
        LIGHTGRAY,
        [](Button& self, Game& game) {
            if (!self.IsLeftClicked())
                return;

            game.GetSceneManager().GotoNextScene(new PlayScene());
        }
    );
    // exit button
    auto exit_button = new Button(
        play_button->GetX(),
        play_button->GetY() + play_button->GetHeight() + button_gap,
        button_width,
        button_height,
        WHITE,
        LIGHTGRAY,
        [](Button& self, Game& game) {
            if (!self.IsLeftClicked())
                return;

            game.Close();
        }
    );
    this->widget_manager.AddWidget(play_button);
    this->widget_manager.AddWidget(exit_button);
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

    this->widget_manager.Update(game);
}

void MainMenuScene::Render() {
    for (auto& rect : this->rects) {
        DrawRectangle(rect.x, rect.y, rect.w, rect.h, rect.color);
    }

    this->widget_manager.Render();
}

} // namespace WaveRush

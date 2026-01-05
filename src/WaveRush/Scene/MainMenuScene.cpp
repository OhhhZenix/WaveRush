#include "WaveRush/Scene/MainMenuScene.hpp"

#include <raylib.h>

#include "WaveRush/Constants.hpp"
#include "WaveRush/Game.hpp"
#include "WaveRush/Scene/PlayScene.hpp"
#include "WaveRush/Utils.hpp"
#include "WaveRush/Widget/Button.hpp"
#include "WaveRush/Widget/Label.hpp"

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

    auto game_title = new Label();
    game_title->SetText("Wave Rush");
    game_title->SetFontSize(48);
    game_title->SetColor(WHITE);
    game_title->SetX((GAME_WIDTH - (48 * 5)) / 2);
    game_title->SetY(40);
    this->widget_manager.AddWidget(game_title);

    auto button_gap = 20;
    auto button_width = 180;
    auto button_height = 60;
    auto button_count = 2;
    auto button_font_size = 24;
    auto play_button = new Button();
    play_button->SetX((GAME_WIDTH - button_width) / 2);
    play_button->SetY((GAME_HEIGHT - (button_height * button_count)) / 2);
    play_button->SetWidth(button_width);
    play_button->SetHeight(button_height);
    play_button->SetOnClick([](Button& self, Game& game) {
        if (!self.IsLeftClicked())
            return;

        game.GetSceneManager().GotoNextScene(new PlayScene());
    });
    play_button->SetText("Play");
    play_button->SetFontSize(button_font_size);
    auto exit_button = new Button();
    exit_button->SetX(play_button->GetX());
    exit_button->SetY(
        play_button->GetY() + play_button->GetHeight() + button_gap
    );
    exit_button->SetWidth(button_width);
    exit_button->SetHeight(button_height);
    exit_button->SetOnClick([](Button& self, Game& game) {
        if (!self.IsLeftClicked())
            return;

        game.Close();
    });
    exit_button->SetText("Quit");
    exit_button->SetFontSize(button_font_size);
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
